//
// Created by adam on 12.05.22.
//
#include <lib.h>
#include <sys/signal.h>
#include <minix/rs.h>

int get_pm_endpt(endpoint_t *pt)
{
    return minix_rs_lookup("pm", pt);
}

pid_t getlcapid(pid_t pid_1, pid_t pid_2)
{
    endpoint_t pm_ep;
    message m;
    m.m_m1.m1i1 = pid_1;
    m.m_m1.m1i2 = pid_2;
    int return_value;
    if (get_pm_endpt(&pm_ep) != 0)
    {
        errno = ENOSYS;
        return -1;
    }
    return_value = _syscall(pm_ep, PM_GETLCAPID, &m);

    switch (return_value) {
        case EINVAL:
            errno = EINVAL;
            return -1;
        case ESRCH:
            errno = ESRCH;
            return -1;
        default:
            return m.m1_i1;
    }
}