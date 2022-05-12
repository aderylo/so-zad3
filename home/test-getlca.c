//
// Created by adam on 11.05.22.
//
#include <stdio.h>
#include <lib.h>
#include <minix/rs.h>

int main() {
    message m;
    m.m_m1.m1i1 = 9;
    m.m_m1.m1i2 = 6;
    endpoint_t pm_ep;
    minix_rs_lookup("pm", &pm_ep);
    int y = _syscall(pm_ep, PM_GETLCAPID, &m);
    printf("Syscall returned: %d\n", y);
    printf("LCA returned by syscall: %d\n", m.m1_i1);

    //    printf("Here is your lca: %d \nAnd here is syscal:: %d ", m.m_m1.m1i1, y);
    return 0;
}