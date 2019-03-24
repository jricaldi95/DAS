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
extern char *STD_STANDARD;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );


int work_p_2188849903_sub_1928526409_1032961590(char *t1, int t2)
{
    char t3[248];
    char t4[8];
    char t8[8];
    char t14[8];
    int t0;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    int t20;
    int t21;
    int t22;
    unsigned char t23;
    int t24;

LAB0:    t5 = (t3 + 4U);
    t6 = ((STD_STANDARD) + 832);
    t7 = (t5 + 88U);
    *((char **)t7) = t6;
    t9 = (t5 + 56U);
    *((char **)t9) = t8;
    xsi_type_set_default_value(t6, t8, 0);
    t10 = (t5 + 80U);
    *((unsigned int *)t10) = 4U;
    t11 = (t3 + 124U);
    t12 = ((STD_STANDARD) + 832);
    t13 = (t11 + 88U);
    *((char **)t13) = t12;
    t15 = (t11 + 56U);
    *((char **)t15) = t14;
    xsi_type_set_default_value(t12, t14, 0);
    t16 = (t11 + 80U);
    *((unsigned int *)t16) = 4U;
    t17 = (t4 + 4U);
    *((int *)t17) = t2;
    t18 = (t5 + 56U);
    t19 = *((char **)t18);
    t18 = (t19 + 0);
    *((int *)t18) = 1;
    t20 = 0;
    t21 = 128;

LAB2:    if (t20 <= t21)
        goto LAB3;

LAB5:    t6 = (t11 + 56U);
    t7 = *((char **)t6);
    t20 = *((int *)t7);
    t0 = t20;

LAB1:    return t0;
LAB3:    t6 = (t11 + 56U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    *((int *)t6) = t20;
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t22 = *((int *)t7);
    t23 = (t22 >= t2);
    if (t23 != 0)
        goto LAB5;

LAB6:    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t22 = *((int *)t7);
    t24 = (t22 * 2);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    t6 = (t9 + 0);
    *((int *)t6) = t24;

LAB4:    if (t20 == t21)
        goto LAB5;

LAB7:    t22 = (t20 + 1);
    t20 = t22;
    goto LAB2;

LAB8:;
}

int work_p_2188849903_sub_25223515_1032961590(char *t1, unsigned char t2, int t3, int t4)
{
    char t6[16];
    int t0;
    char *t7;
    char *t8;
    char *t9;

LAB0:    t7 = (t6 + 4U);
    *((unsigned char *)t7) = t2;
    t8 = (t6 + 5U);
    *((int *)t8) = t3;
    t9 = (t6 + 9U);
    *((int *)t9) = t4;
    if (t2 != 0)
        goto LAB2;

LAB4:    t0 = t4;

LAB1:    return t0;
LAB2:    t0 = t3;
    goto LAB1;

LAB3:    t0 = t3;
    goto LAB1;

LAB5:    goto LAB3;

LAB6:    goto LAB3;

LAB7:;
}

char *work_p_2188849903_sub_2422524777_1032961590(char *t1, char *t2, double t3, int t4, int t5)
{
    char t7[24];
    char t11[16];
    char *t0;
    char *t8;
    char *t9;
    char *t10;
    double t12;
    double t13;
    int t14;
    unsigned char t15;
    unsigned char t16;
    double t17;
    double t18;
    int t19;
    char *t20;
    char *t21;
    unsigned int t22;
    char *t23;
    int t24;
    char *t25;
    int t26;
    char *t27;
    int t28;
    char *t29;
    char *t30;
    int t31;
    unsigned int t32;

LAB0:    t8 = (t7 + 4U);
    *((double *)t8) = t3;
    t9 = (t7 + 12U);
    *((int *)t9) = t4;
    t10 = (t7 + 16U);
    *((int *)t10) = t5;
    t12 = xsi_vhdl_pow_double(2.0000000000000000, t5);
    t13 = (t3 * t12);
    t15 = (t13 >= 0);
    if (t15 == 1)
        goto LAB2;

LAB3:    t18 = (t13 - 0.50000000000000000);
    t14 = ((int)(t18));

LAB4:    t19 = (t4 + t5);
    t20 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t11, t14, t19);
    t21 = (t11 + 12U);
    t22 = *((unsigned int *)t21);
    t22 = (t22 * 1U);
    t0 = xsi_get_transient_memory(t22);
    memcpy(t0, t20, t22);
    t23 = (t11 + 0U);
    t24 = *((int *)t23);
    t25 = (t11 + 4U);
    t26 = *((int *)t25);
    t27 = (t11 + 8U);
    t28 = *((int *)t27);
    t29 = (t2 + 0U);
    t30 = (t29 + 0U);
    *((int *)t30) = t24;
    t30 = (t29 + 4U);
    *((int *)t30) = t26;
    t30 = (t29 + 8U);
    *((int *)t30) = t28;
    t31 = (t26 - t24);
    t32 = (t31 * t28);
    t32 = (t32 + 1);
    t30 = (t29 + 12U);
    *((unsigned int *)t30) = t32;

LAB1:    return t0;
LAB2:    t16 = (t13 >= 2147483647);
    if (t16 == 1)
        goto LAB5;

LAB6:    t17 = (t13 + 0.50000000000000000);
    t14 = ((int)(t17));
    goto LAB4;

LAB5:    t14 = 2147483647;
    goto LAB4;

LAB7:;
}


extern void work_p_2188849903_init()
{
	static char *se[] = {(void *)work_p_2188849903_sub_1928526409_1032961590,(void *)work_p_2188849903_sub_25223515_1032961590,(void *)work_p_2188849903_sub_2422524777_1032961590};
	xsi_register_didat("work_p_2188849903", "isim/ps2ReceiverTest_isim_beh.exe.sim/work/p_2188849903.didat");
	xsi_register_subprogram_executes(se);
}
