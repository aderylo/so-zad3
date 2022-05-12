//
// Created by adam on 11.05.22.
//
#include <stdio.h>
#include "pm.h"
#include "mproc.h" // ten tajemniczy include przyda się nam w zadaniu 3 ;)
#include <limits.h> // w sumie to ten też

int is_pid_in_range(int pid) {
    return !(pid < 0 || pid >= NR_PROCS);
}

int is_proc_in_use(int pid) {
    return (mproc[pid].mp_flags & IN_USE);
}

int get_depth(int pid) {
    if (!is_pid_in_range(pid))
        return -1;

    int parent = mproc[mproc[pid].mp_parent].mp_pid;
    int depth = 0;
    while (parent) {
        if (parent == pid)
            break;

        pid = parent;
        depth++;
    }

    return depth;
}


int do_getlca(void) {
    int depth_1, depth_2, lower_pid, higher_pid, diff, min_depth;
    int pid1 = m_in.m1_i1;
    int pid2 = m_in.m1_i2;

    mp->mp_reply.m1_i1 = -1;

    if (!is_pid_in_range(pid1) ||
        !is_pid_in_range(pid2) ||
        !is_proc_in_use(pid1) ||
        !is_proc_in_use(pid2))
        return EINVAL;


    depth_1 = get_depth(pid1);
    depth_2 = get_depth(pid2);

    if (depth_1 <= 0 || depth_2 <= 0 || pid1 == pid2) {
        return ESRCH;
    }

    diff = (depth_1 > depth_2) ? (depth_1 - depth_2) : (depth_2 - depth_1);
    lower_pid = (depth_1 >= depth_2) ? (pid1) : (pid2);
    higher_pid = (depth_1 >= depth_2) ? (pid2) : (pid1);
    min_depth = (depth_1 >= depth_2) ? (depth_1) : (depth_2);

    // align depths
    for (int i = 0; i < diff; ++i) {
        lower_pid = mproc[mproc[lower_pid].mp_parent].mp_pid;
    }

    // all processes except proc:init have some lca
    for (int i = 0; i < min_depth; ++i) {
        lower_pid = mproc[mproc[lower_pid].mp_parent].mp_pid;
        higher_pid = mproc[mproc[higher_pid].mp_parent].mp_pid;

        if (lower_pid == higher_pid) {
            mp->mp_reply.m1_i1 = lower_pid;
            break;
        }
    }

    return (OK);
}
