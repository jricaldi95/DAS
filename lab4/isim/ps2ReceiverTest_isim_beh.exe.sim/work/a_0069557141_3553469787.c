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
static const char *ng0 = "F:/DAS/lab4/ps2receivertest.vhd";
extern char *IEEE_P_2592010699;
extern char *STD_TEXTIO;

unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );


static void work_a_0069557141_3553469787_p_0(char *t0)
{
    int64 t1;
    int64 t2;
    int64 t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int64 t9;
    int64 t10;
    int64 t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    int64 t17;
    int64 t18;
    int64 t19;
    int64 t20;
    int64 t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;

LAB0:    xsi_set_current_line(113, ng0);

LAB3:    t1 = (50 * 1000000LL);
    t2 = (5 * 1000LL);
    t3 = (t1 + t2);
    t4 = (t0 + 6008);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_delta(t4, 0U, 1, t3);
    t9 = (500 * 1000000000LL);
    t10 = (5 * 1000LL);
    t11 = (t9 + t10);
    t12 = (t0 + 6008);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    *((unsigned char *)t16) = (unsigned char)2;
    xsi_driver_subsequent_trans_delta(t12, 0U, 1, t11);
    t17 = (500 * 1000000000LL);
    t18 = (50 * 1000000LL);
    t19 = (t17 + t18);
    t20 = (5 * 1000LL);
    t21 = (t19 + t20);
    t22 = (t0 + 6008);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    *((unsigned char *)t26) = (unsigned char)3;
    xsi_driver_subsequent_trans_delta(t22, 0U, 1, t21);
    t27 = (t0 + 6008);
    xsi_driver_intertial_reject(t27, t3, t3);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0069557141_3553469787_p_1(char *t0)
{
    char *t1;
    char *t2;
    int64 t3;
    int64 t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(119, ng0);

LAB3:    t1 = (t0 + 2448U);
    t2 = *((char **)t1);
    t3 = *((int64 *)t2);
    t4 = (t3 / 2);
    t1 = (t0 + 1032U);
    t5 = *((char **)t1);
    t6 = *((unsigned char *)t5);
    t7 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t6);
    t1 = (t0 + 6072);
    t8 = (t1 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = t7;
    xsi_driver_first_trans_delta(t1, 0U, 1, t4);
    t12 = (t0 + 6072);
    xsi_driver_intertial_reject(t12, t4, t4);

LAB2:    t13 = (t0 + 5800);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0069557141_3553469787_p_2(char *t0)
{
    char t6[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    int t9;
    unsigned int t10;
    int64 t11;
    int t12;
    int t13;
    int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned char t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;

LAB0:    t1 = (t0 + 4240U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(126, ng0);
    t2 = (t0 + 4048);
    t3 = (t0 + 3088U);
    t4 = (t0 + 9604);
    t7 = (t6 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 1;
    t8 = (t7 + 4U);
    *((int *)t8) = 25;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t9 = (25 - 1);
    t10 = (t9 * 1);
    t10 = (t10 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t10;
    std_textio_write7(STD_TEXTIO, t2, t3, t4, t6, (unsigned char)0, 0);
    xsi_set_current_line(129, ng0);
    t11 = (5 * 1000LL);
    t2 = (t0 + 4048);
    xsi_process_wait(t2, t11);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(130, ng0);

LAB8:
LAB9:    xsi_set_current_line(132, ng0);
    t11 = (100 * 1000000000LL);
    t2 = (t0 + 4048);
    xsi_process_wait(t2, t11);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB10:;
LAB11:    goto LAB2;

LAB12:    xsi_set_current_line(133, ng0);
    t2 = (t0 + 9629);
    *((int *)t2) = 1;
    t3 = (t0 + 9633);
    *((int *)t3) = 23;
    t9 = 1;
    t12 = 23;

LAB16:    if (t9 <= t12)
        goto LAB17;

LAB19:    xsi_set_current_line(139, ng0);
    t11 = (100 * 1000000000LL);
    t2 = (t0 + 4048);
    xsi_process_wait(t2, t11);

LAB27:    *((char **)t1) = &&LAB28;
    goto LAB1;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

LAB17:    xsi_set_current_line(134, ng0);
    t4 = (t0 + 2568U);
    t5 = *((char **)t4);
    t4 = (t0 + 9629);
    t13 = *((int *)t4);
    t14 = (t13 - 1);
    t10 = (t14 * 1);
    t15 = (8U * t10);
    t16 = (0 + t15);
    t17 = (t16 + 0U);
    t7 = (t5 + t17);
    t18 = *((unsigned char *)t7);
    t8 = (t0 + 6136);
    t19 = (t8 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    *((unsigned char *)t22) = t18;
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 2568U);
    t3 = *((char **)t2);
    t2 = (t0 + 9629);
    t13 = *((int *)t2);
    t14 = (t13 - 1);
    t10 = (t14 * 1);
    t15 = (8U * t10);
    t16 = (0 + t15);
    t17 = (t16 + 1U);
    t4 = (t3 + t17);
    t18 = *((unsigned char *)t4);
    t5 = (t0 + 6200);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t19 = (t8 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = t18;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(136, ng0);
    t11 = (40 * 1000000LL);
    t2 = (t0 + 4048);
    xsi_process_wait(t2, t11);

LAB22:    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB18:    t2 = (t0 + 9629);
    t9 = *((int *)t2);
    t3 = (t0 + 9633);
    t12 = *((int *)t3);
    if (t9 == t12)
        goto LAB19;

LAB24:    t13 = (t9 + 1);
    t9 = t13;
    t4 = (t0 + 9629);
    *((int *)t4) = t9;
    goto LAB16;

LAB20:    goto LAB18;

LAB21:    goto LAB20;

LAB23:    goto LAB21;

LAB25:    xsi_set_current_line(140, ng0);
    t2 = (t0 + 9637);
    *((int *)t2) = 1;
    t3 = (t0 + 9641);
    *((int *)t3) = 23;
    t9 = 1;
    t12 = 23;

LAB29:    if (t9 <= t12)
        goto LAB30;

LAB32:    xsi_set_current_line(146, ng0);
    t11 = (100 * 1000000000LL);
    t2 = (t0 + 4048);
    xsi_process_wait(t2, t11);

LAB40:    *((char **)t1) = &&LAB41;
    goto LAB1;

LAB26:    goto LAB25;

LAB28:    goto LAB26;

LAB30:    xsi_set_current_line(141, ng0);
    t4 = (t0 + 2568U);
    t5 = *((char **)t4);
    t4 = (t0 + 9637);
    t13 = *((int *)t4);
    t14 = (t13 - 1);
    t10 = (t14 * 1);
    t15 = (8U * t10);
    t16 = (0 + t15);
    t17 = (t16 + 0U);
    t7 = (t5 + t17);
    t18 = *((unsigned char *)t7);
    t8 = (t0 + 6136);
    t19 = (t8 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    *((unsigned char *)t22) = t18;
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(142, ng0);
    t2 = (t0 + 2568U);
    t3 = *((char **)t2);
    t2 = (t0 + 9637);
    t13 = *((int *)t2);
    t14 = (t13 - 1);
    t10 = (t14 * 1);
    t15 = (8U * t10);
    t16 = (0 + t15);
    t17 = (t16 + 1U);
    t4 = (t3 + t17);
    t18 = *((unsigned char *)t4);
    t5 = (t0 + 6200);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t19 = (t8 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = t18;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(143, ng0);
    t11 = (40 * 1000000LL);
    t2 = (t0 + 4048);
    xsi_process_wait(t2, t11);

LAB35:    *((char **)t1) = &&LAB36;
    goto LAB1;

LAB31:    t2 = (t0 + 9637);
    t9 = *((int *)t2);
    t3 = (t0 + 9641);
    t12 = *((int *)t3);
    if (t9 == t12)
        goto LAB32;

LAB37:    t13 = (t9 + 1);
    t9 = t13;
    t4 = (t0 + 9637);
    *((int *)t4) = t9;
    goto LAB29;

LAB33:    goto LAB31;

LAB34:    goto LAB33;

LAB36:    goto LAB34;

LAB38:    xsi_set_current_line(147, ng0);
    t2 = (t0 + 9645);
    *((int *)t2) = 1;
    t3 = (t0 + 9649);
    *((int *)t3) = 23;
    t9 = 1;
    t12 = 23;

LAB42:    if (t9 <= t12)
        goto LAB43;

LAB45:    xsi_set_current_line(153, ng0);
    t11 = (100 * 1000000000LL);
    t2 = (t0 + 4048);
    xsi_process_wait(t2, t11);

LAB53:    *((char **)t1) = &&LAB54;
    goto LAB1;

LAB39:    goto LAB38;

LAB41:    goto LAB39;

LAB43:    xsi_set_current_line(148, ng0);
    t4 = (t0 + 2688U);
    t5 = *((char **)t4);
    t4 = (t0 + 9645);
    t13 = *((int *)t4);
    t14 = (t13 - 1);
    t10 = (t14 * 1);
    t15 = (8U * t10);
    t16 = (0 + t15);
    t17 = (t16 + 0U);
    t7 = (t5 + t17);
    t18 = *((unsigned char *)t7);
    t8 = (t0 + 6136);
    t19 = (t8 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    *((unsigned char *)t22) = t18;
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(149, ng0);
    t2 = (t0 + 2688U);
    t3 = *((char **)t2);
    t2 = (t0 + 9645);
    t13 = *((int *)t2);
    t14 = (t13 - 1);
    t10 = (t14 * 1);
    t15 = (8U * t10);
    t16 = (0 + t15);
    t17 = (t16 + 1U);
    t4 = (t3 + t17);
    t18 = *((unsigned char *)t4);
    t5 = (t0 + 6200);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t19 = (t8 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = t18;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(150, ng0);
    t11 = (40 * 1000000LL);
    t2 = (t0 + 4048);
    xsi_process_wait(t2, t11);

LAB48:    *((char **)t1) = &&LAB49;
    goto LAB1;

LAB44:    t2 = (t0 + 9645);
    t9 = *((int *)t2);
    t3 = (t0 + 9649);
    t12 = *((int *)t3);
    if (t9 == t12)
        goto LAB45;

LAB50:    t13 = (t9 + 1);
    t9 = t13;
    t4 = (t0 + 9645);
    *((int *)t4) = t9;
    goto LAB42;

LAB46:    goto LAB44;

LAB47:    goto LAB46;

LAB49:    goto LAB47;

LAB51:    xsi_set_current_line(154, ng0);
    t2 = (t0 + 9653);
    *((int *)t2) = 1;
    t3 = (t0 + 9657);
    *((int *)t3) = 23;
    t9 = 1;
    t12 = 23;

LAB55:    if (t9 <= t12)
        goto LAB56;

LAB58:    xsi_set_current_line(160, ng0);
    t11 = (500 * 1000000000LL);
    t2 = (t0 + 4048);
    xsi_process_wait(t2, t11);

LAB66:    *((char **)t1) = &&LAB67;
    goto LAB1;

LAB52:    goto LAB51;

LAB54:    goto LAB52;

LAB56:    xsi_set_current_line(155, ng0);
    t4 = (t0 + 2568U);
    t5 = *((char **)t4);
    t4 = (t0 + 9653);
    t13 = *((int *)t4);
    t14 = (t13 - 1);
    t10 = (t14 * 1);
    t15 = (8U * t10);
    t16 = (0 + t15);
    t17 = (t16 + 0U);
    t7 = (t5 + t17);
    t18 = *((unsigned char *)t7);
    t8 = (t0 + 6136);
    t19 = (t8 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    *((unsigned char *)t22) = t18;
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(156, ng0);
    t2 = (t0 + 2568U);
    t3 = *((char **)t2);
    t2 = (t0 + 9653);
    t13 = *((int *)t2);
    t14 = (t13 - 1);
    t10 = (t14 * 1);
    t15 = (8U * t10);
    t16 = (0 + t15);
    t17 = (t16 + 1U);
    t4 = (t3 + t17);
    t18 = *((unsigned char *)t4);
    t5 = (t0 + 6200);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t19 = (t8 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = t18;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(157, ng0);
    t11 = (40 * 1000000LL);
    t2 = (t0 + 4048);
    xsi_process_wait(t2, t11);

LAB61:    *((char **)t1) = &&LAB62;
    goto LAB1;

LAB57:    t2 = (t0 + 9653);
    t9 = *((int *)t2);
    t3 = (t0 + 9657);
    t12 = *((int *)t3);
    if (t9 == t12)
        goto LAB58;

LAB63:    t13 = (t9 + 1);
    t9 = t13;
    t4 = (t0 + 9653);
    *((int *)t4) = t9;
    goto LAB55;

LAB59:    goto LAB57;

LAB60:    goto LAB59;

LAB62:    goto LAB60;

LAB64:    goto LAB8;

LAB65:    goto LAB64;

LAB67:    goto LAB65;

}

static void work_a_0069557141_3553469787_p_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    unsigned int t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 4488U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(169, ng0);

LAB6:    t2 = (t0 + 5816);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    t3 = (t0 + 5816);
    *((int *)t3) = 0;
    xsi_set_current_line(170, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t2 = (t0 + 9661);
    t5 = 1;
    if (8U == 8U)
        goto LAB10;

LAB11:    t5 = 0;

LAB12:    if (t5 == 0)
        goto LAB8;

LAB9:    xsi_set_current_line(174, ng0);

LAB18:    t2 = (t0 + 5832);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB5:    t3 = (t0 + 1832U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 == 1)
        goto LAB4;
    else
        goto LAB6;

LAB7:    goto LAB5;

LAB8:    t10 = (t0 + 9669);
    xsi_report(t10, 65U, (unsigned char)2);
    goto LAB9;

LAB10:    t7 = 0;

LAB13:    if (t7 < 8U)
        goto LAB14;
    else
        goto LAB12;

LAB14:    t8 = (t3 + t7);
    t9 = (t2 + t7);
    if (*((unsigned char *)t8) != *((unsigned char *)t9))
        goto LAB11;

LAB15:    t7 = (t7 + 1);
    goto LAB13;

LAB16:    t3 = (t0 + 5832);
    *((int *)t3) = 0;
    xsi_set_current_line(175, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t2 = (t0 + 9734);
    t5 = 1;
    if (8U == 8U)
        goto LAB22;

LAB23:    t5 = 0;

LAB24:    if (t5 == 0)
        goto LAB20;

LAB21:    xsi_set_current_line(179, ng0);

LAB30:    t2 = (t0 + 5848);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB31;
    goto LAB1;

LAB17:    t3 = (t0 + 1832U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 == 1)
        goto LAB16;
    else
        goto LAB18;

LAB19:    goto LAB17;

LAB20:    t10 = (t0 + 9742);
    xsi_report(t10, 68U, (unsigned char)2);
    goto LAB21;

LAB22:    t7 = 0;

LAB25:    if (t7 < 8U)
        goto LAB26;
    else
        goto LAB24;

LAB26:    t8 = (t3 + t7);
    t9 = (t2 + t7);
    if (*((unsigned char *)t8) != *((unsigned char *)t9))
        goto LAB23;

LAB27:    t7 = (t7 + 1);
    goto LAB25;

LAB28:    t3 = (t0 + 5848);
    *((int *)t3) = 0;
    xsi_set_current_line(180, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t2 = (t0 + 9810);
    t5 = 1;
    if (8U == 8U)
        goto LAB34;

LAB35:    t5 = 0;

LAB36:    if (t5 == 0)
        goto LAB32;

LAB33:    xsi_set_current_line(184, ng0);

LAB42:    t2 = (t0 + 5864);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB43;
    goto LAB1;

LAB29:    t3 = (t0 + 1832U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 == 1)
        goto LAB28;
    else
        goto LAB30;

LAB31:    goto LAB29;

LAB32:    t10 = (t0 + 9818);
    xsi_report(t10, 51U, (unsigned char)2);
    goto LAB33;

LAB34:    t7 = 0;

LAB37:    if (t7 < 8U)
        goto LAB38;
    else
        goto LAB36;

LAB38:    t8 = (t3 + t7);
    t9 = (t2 + t7);
    if (*((unsigned char *)t8) != *((unsigned char *)t9))
        goto LAB35;

LAB39:    t7 = (t7 + 1);
    goto LAB37;

LAB40:    t3 = (t0 + 5864);
    *((int *)t3) = 0;
    xsi_set_current_line(185, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t2 = (t0 + 9869);
    t5 = 1;
    if (8U == 8U)
        goto LAB46;

LAB47:    t5 = 0;

LAB48:    if (t5 == 0)
        goto LAB44;

LAB45:    goto LAB2;

LAB41:    t3 = (t0 + 1832U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 == 1)
        goto LAB40;
    else
        goto LAB42;

LAB43:    goto LAB41;

LAB44:    t10 = (t0 + 9877);
    xsi_report(t10, 67U, (unsigned char)2);
    goto LAB45;

LAB46:    t7 = 0;

LAB49:    if (t7 < 8U)
        goto LAB50;
    else
        goto LAB48;

LAB50:    t8 = (t3 + t7);
    t9 = (t2 + t7);
    if (*((unsigned char *)t8) != *((unsigned char *)t9))
        goto LAB47;

LAB51:    t7 = (t7 + 1);
    goto LAB49;

}

static void work_a_0069557141_3553469787_p_4(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    unsigned char t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    char *t10;
    unsigned char t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;

LAB0:    xsi_set_current_line(194, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5880);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(195, ng0);
    t1 = (t0 + 1832U);
    t6 = *((char **)t1);
    t7 = *((unsigned char *)t6);
    t8 = (t7 == (unsigned char)2);
    if (t8 == 1)
        goto LAB7;

LAB8:    t5 = (unsigned char)0;

LAB9:    if (t5 == 0)
        goto LAB5;

LAB6:    goto LAB3;

LAB5:    t15 = (t0 + 9944);
    xsi_report(t15, 34U, (unsigned char)1);
    goto LAB6;

LAB7:    t1 = (t0 + 1672U);
    t9 = *((char **)t1);
    t1 = xsi_get_transient_memory(8U);
    memset(t1, 0, 8U);
    t10 = t1;
    memset(t10, (unsigned char)2, 8U);
    t11 = 1;
    if (8U == 8U)
        goto LAB10;

LAB11:    t11 = 0;

LAB12:    t5 = t11;
    goto LAB9;

LAB10:    t12 = 0;

LAB13:    if (t12 < 8U)
        goto LAB14;
    else
        goto LAB12;

LAB14:    t13 = (t9 + t12);
    t14 = (t1 + t12);
    if (*((unsigned char *)t13) != *((unsigned char *)t14))
        goto LAB11;

LAB15:    t12 = (t12 + 1);
    goto LAB13;

}

static void work_a_0069557141_3553469787_p_5(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    int64 t5;
    char *t6;
    char *t7;
    int64 t8;
    unsigned char t9;

LAB0:    xsi_set_current_line(204, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5896);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(205, ng0);
    t1 = (t0 + 2112U);
    t5 = xsi_signal_get_last_event(t1);
    t6 = (t0 + 2448U);
    t7 = *((char **)t6);
    t8 = *((int64 *)t7);
    t9 = (t5 <= t8);
    if (t9 == 0)
        goto LAB5;

LAB6:    goto LAB3;

LAB5:    t6 = (t0 + 9978);
    xsi_report(t6, 54U, (unsigned char)1);
    goto LAB6;

}

static void work_a_0069557141_3553469787_p_6(char *t0)
{
    int64 t1;
    char *t2;
    char *t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(192, ng0);
    t1 = (0 * 1000LL);
    t2 = (t0 + 1192U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t2 = (t0 + 6264);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = t4;
    xsi_driver_first_trans_delta(t2, 0U, 1, t1);
    t2 = (t0 + 5912);
    *((int *)t2) = 1;

LAB1:    return;
}

static void work_a_0069557141_3553469787_p_7(char *t0)
{
    int64 t1;
    char *t2;
    char *t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(205, ng0);
    t1 = (0 * 1000LL);
    t2 = (t0 + 1832U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t2 = (t0 + 6328);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = t4;
    xsi_driver_first_trans_delta(t2, 0U, 1, t1);
    t2 = (t0 + 5928);
    *((int *)t2) = 1;

LAB1:    return;
}


extern void work_a_0069557141_3553469787_init()
{
	static char *pe[] = {(void *)work_a_0069557141_3553469787_p_0,(void *)work_a_0069557141_3553469787_p_1,(void *)work_a_0069557141_3553469787_p_2,(void *)work_a_0069557141_3553469787_p_3,(void *)work_a_0069557141_3553469787_p_4,(void *)work_a_0069557141_3553469787_p_5,(void *)work_a_0069557141_3553469787_p_6,(void *)work_a_0069557141_3553469787_p_7};
	xsi_register_didat("work_a_0069557141_3553469787", "isim/ps2ReceiverTest_isim_beh.exe.sim/work/a_0069557141_3553469787.didat");
	xsi_register_executes(pe);
}
