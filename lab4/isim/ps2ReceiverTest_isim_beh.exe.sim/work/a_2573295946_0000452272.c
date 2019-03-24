/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "F:/DAS/common/synchronizer.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_2573295946_0000452272_p_0(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    unsigned char t14;
    int t15;
    int t16;
    int t17;
    int t18;
    char *t19;
    int t20;
    int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;

LAB0:    xsi_set_current_line(41, ng0);
    t1 = (t0 + 2048U);
    t2 = *((char **)t1);
    t3 = (2 - 1);
    t4 = (t3 - 1);
    t5 = (t4 * -1);
    t6 = (1U * t5);
    t7 = (0 + t6);
    t1 = (t2 + t7);
    t8 = *((unsigned char *)t1);
    t9 = (t0 + 3432);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t8;
    xsi_driver_first_trans_fast_port(t9);
    xsi_set_current_line(42, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t8 = *((unsigned char *)t2);
    t14 = (t8 == (unsigned char)2);
    if (t14 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1152U);
    t8 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t8 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 3352);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(43, ng0);
    t1 = xsi_get_transient_memory(2U);
    memset(t1, 0, 2U);
    t9 = t1;
    memset(t9, (unsigned char)3, 2U);
    t10 = (t0 + 2048U);
    t11 = *((char **)t10);
    t10 = (t11 + 0);
    memcpy(t10, t1, 2U);
    goto LAB3;

LAB5:    xsi_set_current_line(45, ng0);
    t3 = (2 - 1);
    t2 = (t0 + 5082);
    *((int *)t2) = t3;
    t9 = (t0 + 5086);
    *((int *)t9) = 1;
    t4 = t3;
    t15 = 1;

LAB7:    if (t4 >= t15)
        goto LAB8;

LAB10:    xsi_set_current_line(48, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t8 = *((unsigned char *)t2);
    t1 = (t0 + 2048U);
    t9 = *((char **)t1);
    t3 = (0 - 1);
    t5 = (t3 * -1);
    t6 = (1U * t5);
    t7 = (0 + t6);
    t1 = (t9 + t7);
    *((unsigned char *)t1) = t8;
    goto LAB3;

LAB8:    xsi_set_current_line(46, ng0);
    t10 = (t0 + 2048U);
    t11 = *((char **)t10);
    t10 = (t0 + 5082);
    t16 = *((int *)t10);
    t17 = (t16 - 1);
    t18 = (t17 - 1);
    t5 = (t18 * -1);
    xsi_vhdl_check_range_of_index(1, 0, -1, t17);
    t6 = (1U * t5);
    t7 = (0 + t6);
    t12 = (t11 + t7);
    t14 = *((unsigned char *)t12);
    t13 = (t0 + 2048U);
    t19 = *((char **)t13);
    t13 = (t0 + 5082);
    t20 = *((int *)t13);
    t21 = (t20 - 1);
    t22 = (t21 * -1);
    xsi_vhdl_check_range_of_index(1, 0, -1, *((int *)t13));
    t23 = (1U * t22);
    t24 = (0 + t23);
    t25 = (t19 + t24);
    *((unsigned char *)t25) = t14;

LAB9:    t1 = (t0 + 5082);
    t4 = *((int *)t1);
    t2 = (t0 + 5086);
    t15 = *((int *)t2);
    if (t4 == t15)
        goto LAB10;

LAB11:    t3 = (t4 + -1);
    t4 = t3;
    t9 = (t0 + 5082);
    *((int *)t9) = t4;
    goto LAB7;

}


extern void work_a_2573295946_0000452272_init()
{
	static char *pe[] = {(void *)work_a_2573295946_0000452272_p_0};
	xsi_register_didat("work_a_2573295946_0000452272", "isim/ps2ReceiverTest_isim_beh.exe.sim/work/a_2573295946_0000452272.didat");
	xsi_register_executes(pe);
}
