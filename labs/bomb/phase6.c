int phase_6(int rdi) {
    int r13 = rsp;
    int rsi = rsp;
    read_six_numbers(rdi, rsi);
    r14 = rsp;
    r12d = 0;

    while (1) {
        rbp = r13;  // == rsp
        eax = *rsp - 1;
        if (eax > 5) {
            explode();
        }

        r12d += 1;
        if (r12d == 6) {
            break;
        }
        ebx = r12d;
        do {
            rax = ebx;
            eax = rsp[rax * 4];
            if (eax == rbp[0]) {
                explode();
            }
            ebx += 1;
        } while (ebx <= 5);
        r13 += 4;
    }

    rsi = rsp + 0x18;
    rax = r14;
    rcx = 7;
    do {
        edx = ecx;
        edx -= *rax;
        *rax = edx;
        rax += 4;
    } while (rax != rsi);

    esi = 0;
}