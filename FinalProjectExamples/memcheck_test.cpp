#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *string;
    string = (char *)malloc(sizeof(char)*5);
    return 0;
}

vagrant@Xubuntu-Vagrant:~/ClionProjects/OS_Examples/FinalProjectExamples$ gcc -o Memcheck memcheck_test.cpp
        vagrant@Xubuntu-Vagrant:~/ClionProjects/OS_Examples/FinalProjectExamples$ valgrind --tool=memcheck --leak-check=full ./Memcheck
                                                                                                                        ==4644== Memcheck, a memory error detector
==4644== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==4644== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==4644== Command: ./Memcheck
==4644==
==4644==
==4644== HEAP SUMMARY:
==4644==     in use at exit: 5 bytes in 1 blocks
==4644==   total heap usage: 1 allocs, 0 frees, 5 bytes allocated
==4644==
==4644== 5 bytes in 1 blocks are definitely lost in loss record 1 of 1
==4644==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==4644==    by 0x40053A: main (in /home/vagrant/ClionProjects/OS_Examples/FinalProjectExamples/Memcheck)
==4644==
==4644== LEAK SUMMARY:
==4644==    definitely lost: 5 bytes in 1 blocks
==4644==    indirectly lost: 0 bytes in 0 blocks
==4644==      possibly lost: 0 bytes in 0 blocks
==4644==    still reachable: 0 bytes in 0 blocks
==4644==         suppressed: 0 bytes in 0 blocks
==4644==
==4644== For counts of detected and suppressed errors, rerun with: -v
==4644== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)




