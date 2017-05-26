/*
 * File: SWatch.c
 *
 * Code generated for Simulink model 'SWatch'.
 *
 * Model version                  : 1.144
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Sat Jun  4 11:26:04 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWatch.h"
#include "SWatch_private.h"

/* Named constants for Chart: '<S1>/SWatch' */
#define SWatch_IN_AlarmOn              ((uint8_T)1U)
#define SWatch_IN_Blink                ((uint8_T)2U)
#define SWatch_IN_CronoBackground      ((uint8_T)1U)
#define SWatch_IN_CronoCount           ((uint8_T)1U)
#define SWatch_IN_CronoOff             ((uint8_T)2U)
#define SWatch_IN_CronoOn              ((uint8_T)3U)
#define SWatch_IN_CronoWait            ((uint8_T)2U)
#define SWatch_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define SWatch_IN_ShowAlarm            ((uint8_T)1U)
#define SWatch_IN_alarmmode            ((uint8_T)1U)
#define SWatch_IN_delay                ((uint8_T)3U)
#define SWatch_IN_sethours             ((uint8_T)1U)
#define SWatch_IN_sethours_i           ((uint8_T)2U)
#define SWatch_IN_setminutes           ((uint8_T)2U)
#define SWatch_IN_setminutes_c         ((uint8_T)3U)
#define SWatch_IN_swatchmode           ((uint8_T)2U)
#define SWatch_IN_timemode             ((uint8_T)3U)
#define SWatch_IN_timesetmode          ((uint8_T)4U)
#define SWatch_IN_wait_alarm           ((uint8_T)4U)
#define SWatch_event_Balarm            (5)
#define SWatch_event_Bminus            (2)
#define SWatch_event_Bplus             (1)
#define SWatch_event_Bstop             (6)
#define SWatch_event_Btime             (3)
#define SWatch_event_Btimeset          (4)
#define SWatch_event_tickt             (0)

/* Forward declaration for local functions */
static void SWatc_enter_internal_swatchmode(uint8_T *SWatch_Y_hours, uint8_T
  *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths,
  DW_SWatch_T *SWatch_DW);
static void SWatch_swatchmode(uint8_T *SWatch_Y_hours, uint8_T *SWatch_Y_minutes,
  uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths, uint8_T *SWatch_Y_mode,
  DW_SWatch_T *SWatch_DW);
static void SWatch_Control(uint8_T *SWatch_Y_hours, uint8_T *SWatch_Y_minutes,
  uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths, uint8_T *SWatch_Y_mode,
  DW_SWatch_T *SWatch_DW);
static void SWatch_chartstep_c3_SWatch(uint8_T *SWatch_Y_hours, uint8_T
  *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths,
  uint8_T *SWatch_Y_mode, DW_SWatch_T *SWatch_DW);

/* Function for Chart: '<S1>/SWatch' */
static void SWatc_enter_internal_swatchmode(uint8_T *SWatch_Y_hours, uint8_T
  *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths,
  DW_SWatch_T *SWatch_DW)
{
  /* Entry Internal 'swatchmode': '<S3>:44' */
  switch (SWatch_DW->was_swatchmode) {
   case SWatch_IN_CronoBackground:
    SWatch_DW->is_swatchmode = SWatch_IN_CronoBackground;
    SWatch_DW->was_swatchmode = SWatch_IN_CronoBackground;
    break;

   case SWatch_IN_CronoOff:
    SWatch_DW->is_swatchmode = SWatch_IN_CronoOff;
    SWatch_DW->was_swatchmode = SWatch_IN_CronoOff;

    /* Entry 'CronoOff': '<S3>:159' */
    *SWatch_Y_hours = SWatch_DW->Chours;
    *SWatch_Y_minutes = SWatch_DW->Cminutes;
    *SWatch_Y_seconds = SWatch_DW->Cseconds;
    *SWatch_Y_tenths = SWatch_DW->Ctenths;
    break;

   case SWatch_IN_CronoOn:
    SWatch_DW->is_swatchmode = SWatch_IN_CronoOn;
    SWatch_DW->was_swatchmode = SWatch_IN_CronoOn;
    break;

   default:
    /* Transition: '<S3>:168' */
    SWatch_DW->is_swatchmode = SWatch_IN_CronoOff;
    SWatch_DW->was_swatchmode = SWatch_IN_CronoOff;

    /* Entry 'CronoOff': '<S3>:159' */
    *SWatch_Y_hours = SWatch_DW->Chours;
    *SWatch_Y_minutes = SWatch_DW->Cminutes;
    *SWatch_Y_seconds = SWatch_DW->Cseconds;
    *SWatch_Y_tenths = SWatch_DW->Ctenths;
    break;
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void SWatch_swatchmode(uint8_T *SWatch_Y_hours, uint8_T *SWatch_Y_minutes,
  uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths, uint8_T *SWatch_Y_mode,
  DW_SWatch_T *SWatch_DW)
{
  /* During 'swatchmode': '<S3>:44' */
  if (SWatch_DW->sfEvent == SWatch_event_Btimeset) {
    /* Transition: '<S3>:48' */
    /* Exit Internal 'swatchmode': '<S3>:44' */
    SWatch_DW->is_swatchmode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_Control = SWatch_IN_timesetmode;

    /* Entry 'timesetmode': '<S3>:25' */
    *SWatch_Y_mode = 1U;

    /* Entry Internal 'timesetmode': '<S3>:25' */
    /* Transition: '<S3>:66' */
    SWatch_DW->is_timesetmode = SWatch_IN_sethours;

    /* Entry 'sethours': '<S3>:64' */
    *SWatch_Y_hours = SWatch_DW->hours;
  } else if (SWatch_DW->sfEvent == SWatch_event_Balarm) {
    /* Transition: '<S3>:51' */
    /* Exit Internal 'swatchmode': '<S3>:44' */
    SWatch_DW->is_swatchmode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_Control = SWatch_IN_alarmmode;

    /* Entry 'alarmmode': '<S3>:45' */
    *SWatch_Y_mode = 2U;

    /* Entry Internal 'alarmmode': '<S3>:45' */
    /* Transition: '<S3>:262' */
    if (SWatch_DW->alarm) {
      /* Transition: '<S3>:261' */
      SWatch_DW->is_alarmmode = SWatch_IN_ShowAlarm;
    } else {
      /* Transition: '<S3>:264' */
      *SWatch_Y_minutes = 0U;
      SWatch_DW->is_alarmmode = SWatch_IN_sethours_i;

      /* Entry 'sethours': '<S3>:77' */
      *SWatch_Y_hours = SWatch_DW->ahours;
    }
  } else {
    switch (SWatch_DW->is_swatchmode) {
     case SWatch_IN_CronoBackground:
      /* During 'CronoBackground': '<S3>:175' */
      if (SWatch_DW->sfEvent == SWatch_event_Bplus) {
        /* Transition: '<S3>:209' */
        SWatch_DW->is_swatchmode = SWatch_IN_CronoOn;
        SWatch_DW->was_swatchmode = SWatch_IN_CronoOn;
      } else if (SWatch_DW->sfEvent == SWatch_event_Bstop) {
        /* Transition: '<S3>:210' */
        SWatch_DW->Chours = 0U;
        SWatch_DW->Cminutes = 0U;
        SWatch_DW->Cseconds = 0U;
        SWatch_DW->Ctenths = 0U;
        SWatch_DW->is_swatchmode = SWatch_IN_CronoOff;
        SWatch_DW->was_swatchmode = SWatch_IN_CronoOff;

        /* Entry 'CronoOff': '<S3>:159' */
        *SWatch_Y_hours = SWatch_DW->Chours;
        *SWatch_Y_minutes = SWatch_DW->Cminutes;
        *SWatch_Y_seconds = SWatch_DW->Cseconds;
        *SWatch_Y_tenths = SWatch_DW->Ctenths;
      } else {
        *SWatch_Y_hours = SWatch_DW->Shours;
        *SWatch_Y_minutes = SWatch_DW->Sminutes;
        *SWatch_Y_seconds = SWatch_DW->Sseconds;
        *SWatch_Y_tenths = SWatch_DW->Stenths;
      }
      break;

     case SWatch_IN_CronoOff:
      /* During 'CronoOff': '<S3>:159' */
      if (SWatch_DW->sfEvent == SWatch_event_Bplus) {
        /* Transition: '<S3>:173' */
        SWatch_DW->crono_start = true;
        SWatch_DW->is_swatchmode = SWatch_IN_CronoOn;
        SWatch_DW->was_swatchmode = SWatch_IN_CronoOn;
      }
      break;

     default:
      /* During 'CronoOn': '<S3>:165' */
      if (SWatch_DW->sfEvent == SWatch_event_Bminus) {
        /* Transition: '<S3>:208' */
        SWatch_DW->Shours = SWatch_DW->Chours;
        SWatch_DW->Sminutes = SWatch_DW->Cminutes;
        SWatch_DW->Sseconds = SWatch_DW->Cseconds;
        SWatch_DW->Stenths = SWatch_DW->Ctenths;
        SWatch_DW->is_swatchmode = SWatch_IN_CronoBackground;
        SWatch_DW->was_swatchmode = SWatch_IN_CronoBackground;
      } else if (SWatch_DW->sfEvent == SWatch_event_Bstop) {
        /* Transition: '<S3>:211' */
        SWatch_DW->Chours = 0U;
        SWatch_DW->Cminutes = 0U;
        SWatch_DW->Cseconds = 0U;
        SWatch_DW->Ctenths = 0U;
        SWatch_DW->crono_start = false;
        SWatch_DW->is_swatchmode = SWatch_IN_CronoOff;
        SWatch_DW->was_swatchmode = SWatch_IN_CronoOff;

        /* Entry 'CronoOff': '<S3>:159' */
        *SWatch_Y_hours = SWatch_DW->Chours;
        *SWatch_Y_minutes = SWatch_DW->Cminutes;
        *SWatch_Y_seconds = SWatch_DW->Cseconds;
        *SWatch_Y_tenths = SWatch_DW->Ctenths;
      } else {
        *SWatch_Y_hours = SWatch_DW->Chours;
        *SWatch_Y_minutes = SWatch_DW->Cminutes;
        *SWatch_Y_seconds = SWatch_DW->Cseconds;
        *SWatch_Y_tenths = SWatch_DW->Ctenths;
      }
      break;
    }
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void SWatch_Control(uint8_T *SWatch_Y_hours, uint8_T *SWatch_Y_minutes,
  uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths, uint8_T *SWatch_Y_mode,
  DW_SWatch_T *SWatch_DW)
{
  int32_T tmp;
  uint32_T qY;

  /* During 'Control': '<S3>:14' */
  if (SWatch_DW->sfEvent == SWatch_event_Btime) {
    /* Transition: '<S3>:50' */
    /* Exit Internal 'Control': '<S3>:14' */
    /* Exit Internal 'alarmmode': '<S3>:45' */
    SWatch_DW->is_alarmmode = SWatch_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'swatchmode': '<S3>:44' */
    SWatch_DW->is_swatchmode = SWatch_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'timesetmode': '<S3>:25' */
    SWatch_DW->is_timesetmode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_Control = SWatch_IN_timemode;

    /* Entry 'timemode': '<S3>:24' */
    *SWatch_Y_mode = 0U;
  } else {
    switch (SWatch_DW->is_Control) {
     case SWatch_IN_alarmmode:
      /* During 'alarmmode': '<S3>:45' */
      if (SWatch_DW->sfEvent == SWatch_event_Btimeset) {
        /* Transition: '<S3>:49' */
        /* Exit Internal 'alarmmode': '<S3>:45' */
        SWatch_DW->is_alarmmode = SWatch_IN_NO_ACTIVE_CHILD;
        SWatch_DW->is_Control = SWatch_IN_timesetmode;

        /* Entry 'timesetmode': '<S3>:25' */
        *SWatch_Y_mode = 1U;

        /* Entry Internal 'timesetmode': '<S3>:25' */
        /* Transition: '<S3>:66' */
        SWatch_DW->is_timesetmode = SWatch_IN_sethours;

        /* Entry 'sethours': '<S3>:64' */
        *SWatch_Y_hours = SWatch_DW->hours;
      } else if (SWatch_DW->sfEvent == SWatch_event_Bstop) {
        /* Transition: '<S3>:54' */
        /* Exit Internal 'alarmmode': '<S3>:45' */
        SWatch_DW->is_alarmmode = SWatch_IN_NO_ACTIVE_CHILD;
        SWatch_DW->is_Control = SWatch_IN_swatchmode;

        /* Entry 'swatchmode': '<S3>:44' */
        *SWatch_Y_mode = 3U;
        SWatc_enter_internal_swatchmode(SWatch_Y_hours, SWatch_Y_minutes,
          SWatch_Y_seconds, SWatch_Y_tenths, SWatch_DW);
      } else {
        switch (SWatch_DW->is_alarmmode) {
         case SWatch_IN_ShowAlarm:
          /* During 'ShowAlarm': '<S3>:260' */
          if (SWatch_DW->sfEvent == SWatch_event_Bminus) {
            /* Transition: '<S3>:266' */
            SWatch_DW->alarm = false;
            *SWatch_Y_minutes = 0U;
            SWatch_DW->is_alarmmode = SWatch_IN_sethours_i;

            /* Entry 'sethours': '<S3>:77' */
            *SWatch_Y_hours = SWatch_DW->ahours;
          } else {
            *SWatch_Y_hours = SWatch_DW->ahours;
            *SWatch_Y_minutes = SWatch_DW->aminutes;
          }
          break;

         case SWatch_IN_sethours_i:
          /* During 'sethours': '<S3>:77' */
          if (SWatch_DW->sfEvent == SWatch_event_Balarm) {
            /* Transition: '<S3>:80' */
            SWatch_DW->is_alarmmode = SWatch_IN_setminutes_c;

            /* Entry 'setminutes': '<S3>:81' */
            *SWatch_Y_minutes = SWatch_DW->aminutes;
          } else if (SWatch_DW->sfEvent == SWatch_event_Bplus) {
            /* Transition: '<S3>:82' */
            tmp = (int32_T)(SWatch_DW->ahours + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            SWatch_DW->ahours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
              ((uint8_T)tmp / 24U * 24U));
            SWatch_DW->is_alarmmode = SWatch_IN_sethours_i;

            /* Entry 'sethours': '<S3>:77' */
            *SWatch_Y_hours = SWatch_DW->ahours;
          } else if ((SWatch_DW->sfEvent == SWatch_event_Bminus) &&
                     (SWatch_DW->ahours == 0)) {
            /* Transition: '<S3>:79' */
            SWatch_DW->ahours = 23U;
            SWatch_DW->is_alarmmode = SWatch_IN_sethours_i;

            /* Entry 'sethours': '<S3>:77' */
            *SWatch_Y_hours = SWatch_DW->ahours;
          } else {
            if (SWatch_DW->sfEvent == SWatch_event_Bminus) {
              /* Transition: '<S3>:85' */
              qY = SWatch_DW->ahours - 1U;
              if (qY > SWatch_DW->ahours) {
                qY = 0U;
              }

              SWatch_DW->ahours = (uint8_T)qY;
              SWatch_DW->is_alarmmode = SWatch_IN_sethours_i;

              /* Entry 'sethours': '<S3>:77' */
              *SWatch_Y_hours = SWatch_DW->ahours;
            }
          }
          break;

         default:
          /* During 'setminutes': '<S3>:81' */
          if (SWatch_DW->sfEvent == SWatch_event_Balarm) {
            /* Transition: '<S3>:76' */
            SWatch_DW->alarm = true;
            SWatch_DW->is_alarmmode = SWatch_IN_sethours_i;

            /* Entry 'sethours': '<S3>:77' */
            *SWatch_Y_hours = SWatch_DW->ahours;
          } else if (SWatch_DW->sfEvent == SWatch_event_Bplus) {
            /* Transition: '<S3>:75' */
            tmp = (int32_T)(SWatch_DW->aminutes + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            SWatch_DW->aminutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
              ((uint8_T)tmp / 60U * 60U));
            SWatch_DW->is_alarmmode = SWatch_IN_setminutes_c;

            /* Entry 'setminutes': '<S3>:81' */
            *SWatch_Y_minutes = SWatch_DW->aminutes;
          } else if ((SWatch_DW->sfEvent == SWatch_event_Bminus) &&
                     (SWatch_DW->aminutes == 0)) {
            /* Transition: '<S3>:83' */
            SWatch_DW->aminutes = 59U;
            SWatch_DW->is_alarmmode = SWatch_IN_setminutes_c;

            /* Entry 'setminutes': '<S3>:81' */
            *SWatch_Y_minutes = SWatch_DW->aminutes;
          } else {
            if (SWatch_DW->sfEvent == SWatch_event_Bminus) {
              /* Transition: '<S3>:84' */
              qY = SWatch_DW->aminutes - 1U;
              if (qY > SWatch_DW->aminutes) {
                qY = 0U;
              }

              SWatch_DW->aminutes = (uint8_T)qY;
              SWatch_DW->is_alarmmode = SWatch_IN_setminutes_c;

              /* Entry 'setminutes': '<S3>:81' */
              *SWatch_Y_minutes = SWatch_DW->aminutes;
            }
          }
          break;
        }
      }
      break;

     case SWatch_IN_swatchmode:
      SWatch_swatchmode(SWatch_Y_hours, SWatch_Y_minutes, SWatch_Y_seconds,
                        SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
      break;

     case SWatch_IN_timemode:
      /* During 'timemode': '<S3>:24' */
      if (SWatch_DW->sfEvent == SWatch_event_Btimeset) {
        /* Transition: '<S3>:27' */
        SWatch_DW->is_Control = SWatch_IN_timesetmode;

        /* Entry 'timesetmode': '<S3>:25' */
        *SWatch_Y_mode = 1U;

        /* Entry Internal 'timesetmode': '<S3>:25' */
        /* Transition: '<S3>:66' */
        SWatch_DW->is_timesetmode = SWatch_IN_sethours;

        /* Entry 'sethours': '<S3>:64' */
        *SWatch_Y_hours = SWatch_DW->hours;
      } else if (SWatch_DW->sfEvent == SWatch_event_Balarm) {
        /* Transition: '<S3>:53' */
        SWatch_DW->is_Control = SWatch_IN_alarmmode;

        /* Entry 'alarmmode': '<S3>:45' */
        *SWatch_Y_mode = 2U;

        /* Entry Internal 'alarmmode': '<S3>:45' */
        /* Transition: '<S3>:262' */
        if (SWatch_DW->alarm) {
          /* Transition: '<S3>:261' */
          SWatch_DW->is_alarmmode = SWatch_IN_ShowAlarm;
        } else {
          /* Transition: '<S3>:264' */
          *SWatch_Y_minutes = 0U;
          SWatch_DW->is_alarmmode = SWatch_IN_sethours_i;

          /* Entry 'sethours': '<S3>:77' */
          *SWatch_Y_hours = SWatch_DW->ahours;
        }
      } else if (SWatch_DW->sfEvent == SWatch_event_Bstop) {
        /* Transition: '<S3>:55' */
        SWatch_DW->is_Control = SWatch_IN_swatchmode;

        /* Entry 'swatchmode': '<S3>:44' */
        *SWatch_Y_mode = 3U;
        SWatc_enter_internal_swatchmode(SWatch_Y_hours, SWatch_Y_minutes,
          SWatch_Y_seconds, SWatch_Y_tenths, SWatch_DW);
      } else {
        if (SWatch_DW->sfEvent == SWatch_event_tickt) {
          /* Transition: '<S3>:62' */
          *SWatch_Y_hours = SWatch_DW->hours;
          *SWatch_Y_minutes = SWatch_DW->minutes;
          *SWatch_Y_seconds = SWatch_DW->seconds;
        }
      }
      break;

     default:
      /* During 'timesetmode': '<S3>:25' */
      if (SWatch_DW->sfEvent == SWatch_event_Balarm) {
        /* Transition: '<S3>:52' */
        /* Exit Internal 'timesetmode': '<S3>:25' */
        SWatch_DW->is_timesetmode = SWatch_IN_NO_ACTIVE_CHILD;
        SWatch_DW->is_Control = SWatch_IN_alarmmode;

        /* Entry 'alarmmode': '<S3>:45' */
        *SWatch_Y_mode = 2U;

        /* Entry Internal 'alarmmode': '<S3>:45' */
        /* Transition: '<S3>:262' */
        if (SWatch_DW->alarm) {
          /* Transition: '<S3>:261' */
          SWatch_DW->is_alarmmode = SWatch_IN_ShowAlarm;
        } else {
          /* Transition: '<S3>:264' */
          *SWatch_Y_minutes = 0U;
          SWatch_DW->is_alarmmode = SWatch_IN_sethours_i;

          /* Entry 'sethours': '<S3>:77' */
          *SWatch_Y_hours = SWatch_DW->ahours;
        }
      } else if (SWatch_DW->sfEvent == SWatch_event_Bstop) {
        /* Transition: '<S3>:56' */
        /* Exit Internal 'timesetmode': '<S3>:25' */
        SWatch_DW->is_timesetmode = SWatch_IN_NO_ACTIVE_CHILD;
        SWatch_DW->is_Control = SWatch_IN_swatchmode;

        /* Entry 'swatchmode': '<S3>:44' */
        *SWatch_Y_mode = 3U;
        SWatc_enter_internal_swatchmode(SWatch_Y_hours, SWatch_Y_minutes,
          SWatch_Y_seconds, SWatch_Y_tenths, SWatch_DW);
      } else if (SWatch_DW->is_timesetmode == SWatch_IN_sethours) {
        /* During 'sethours': '<S3>:64' */
        if (SWatch_DW->sfEvent == SWatch_event_Btimeset) {
          /* Transition: '<S3>:67' */
          SWatch_DW->is_timesetmode = SWatch_IN_setminutes;

          /* Entry 'setminutes': '<S3>:65' */
          *SWatch_Y_minutes = SWatch_DW->minutes;
        } else if (SWatch_DW->sfEvent == SWatch_event_Bplus) {
          /* Transition: '<S3>:69' */
          tmp = (int32_T)(SWatch_DW->hours + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          SWatch_DW->hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));
          SWatch_DW->is_timesetmode = SWatch_IN_sethours;

          /* Entry 'sethours': '<S3>:64' */
          *SWatch_Y_hours = SWatch_DW->hours;
        } else if ((SWatch_DW->sfEvent == SWatch_event_Bminus) &&
                   (SWatch_DW->hours == 0)) {
          /* Transition: '<S3>:71' */
          SWatch_DW->hours = 23U;
          SWatch_DW->is_timesetmode = SWatch_IN_sethours;

          /* Entry 'sethours': '<S3>:64' */
          *SWatch_Y_hours = SWatch_DW->hours;
        } else {
          if (SWatch_DW->sfEvent == SWatch_event_Bminus) {
            /* Transition: '<S3>:73' */
            qY = SWatch_DW->hours - 1U;
            if (qY > SWatch_DW->hours) {
              qY = 0U;
            }

            SWatch_DW->hours = (uint8_T)qY;
            SWatch_DW->is_timesetmode = SWatch_IN_sethours;

            /* Entry 'sethours': '<S3>:64' */
            *SWatch_Y_hours = SWatch_DW->hours;
          }
        }
      } else {
        /* During 'setminutes': '<S3>:65' */
        if (SWatch_DW->sfEvent == SWatch_event_Btimeset) {
          /* Transition: '<S3>:68' */
          SWatch_DW->is_timesetmode = SWatch_IN_sethours;

          /* Entry 'sethours': '<S3>:64' */
          *SWatch_Y_hours = SWatch_DW->hours;
        } else if (SWatch_DW->sfEvent == SWatch_event_Bplus) {
          /* Transition: '<S3>:70' */
          tmp = (int32_T)(SWatch_DW->minutes + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          SWatch_DW->minutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 60U * 60U));
          SWatch_DW->is_timesetmode = SWatch_IN_setminutes;

          /* Entry 'setminutes': '<S3>:65' */
          *SWatch_Y_minutes = SWatch_DW->minutes;
        } else if ((SWatch_DW->sfEvent == SWatch_event_Bminus) &&
                   (SWatch_DW->minutes == 0)) {
          /* Transition: '<S3>:72' */
          SWatch_DW->minutes = 59U;
          SWatch_DW->is_timesetmode = SWatch_IN_setminutes;

          /* Entry 'setminutes': '<S3>:65' */
          *SWatch_Y_minutes = SWatch_DW->minutes;
        } else {
          if (SWatch_DW->sfEvent == SWatch_event_Bminus) {
            /* Transition: '<S3>:74' */
            qY = SWatch_DW->minutes - 1U;
            if (qY > SWatch_DW->minutes) {
              qY = 0U;
            }

            SWatch_DW->minutes = (uint8_T)qY;
            SWatch_DW->is_timesetmode = SWatch_IN_setminutes;

            /* Entry 'setminutes': '<S3>:65' */
            *SWatch_Y_minutes = SWatch_DW->minutes;
          }
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void SWatch_chartstep_c3_SWatch(uint8_T *SWatch_Y_hours, uint8_T
  *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths,
  uint8_T *SWatch_Y_mode, DW_SWatch_T *SWatch_DW)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  int32_T tmp;

  /* During: SWatch/SWatch */
  SWatch_Control(SWatch_Y_hours, SWatch_Y_minutes, SWatch_Y_seconds,
                 SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);

  /* During 'TimeCount': '<S3>:15' */
  /* During 'Time': '<S3>:287' */
  /* During 'timecount': '<S3>:296' */
  if (SWatch_DW->sfEvent == SWatch_event_tickt) {
    /* Transition: '<S3>:290' */
    tmp = (int32_T)(SWatch_DW->tenths + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    SWatch_DW->tenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)((uint8_T)
      tmp / 10U * 10U));
    if (SWatch_DW->tenths == 0) {
      /* Transition: '<S3>:294' */
      tmp = (int32_T)(SWatch_DW->seconds + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      SWatch_DW->seconds = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)((uint8_T)
        tmp / 60U * 60U));
      if (SWatch_DW->seconds == 0) {
        /* Transition: '<S3>:302' */
        tmp = (int32_T)(SWatch_DW->minutes + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        SWatch_DW->minutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 60U * 60U));
        if (SWatch_DW->minutes == 0) {
          /* Transition: '<S3>:303' */
          tmp = (int32_T)(SWatch_DW->hours + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          SWatch_DW->hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));

          /* Transition: '<S3>:293' */
        } else {
          /* Transition: '<S3>:292' */
        }
      } else {
        /* Transition: '<S3>:295' */
      }
    } else {
      /* Transition: '<S3>:288' */
    }

    /* Transition: '<S3>:291' */
  }

  /* During 'CronoTime': '<S3>:267' */
  if (SWatch_DW->is_CronoTime == SWatch_IN_CronoCount) {
    /* During 'CronoCount': '<S3>:275' */
    if (SWatch_DW->sfEvent == SWatch_event_tickt) {
      /* Transition: '<S3>:271' */
      tmp = (int32_T)(SWatch_DW->Ctenths + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      SWatch_DW->Ctenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)((uint8_T)
        tmp / 10U * 10U));
      if (SWatch_DW->Ctenths == 0) {
        /* Transition: '<S3>:278' */
        tmp = (int32_T)(SWatch_DW->Cseconds + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        SWatch_DW->Cseconds = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 60U * 60U));
        if (SWatch_DW->Cseconds == 0) {
          /* Transition: '<S3>:276' */
          tmp = (int32_T)(SWatch_DW->Cminutes + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          SWatch_DW->Cminutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 60U * 60U));
          if (SWatch_DW->Cminutes == 0) {
            /* Transition: '<S3>:273' */
            tmp = (int32_T)(SWatch_DW->Chours + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            SWatch_DW->Chours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
              ((uint8_T)tmp / 24U * 24U));

            /* Transition: '<S3>:282' */
          } else {
            /* Transition: '<S3>:283' */
          }
        } else {
          /* Transition: '<S3>:274' */
        }
      } else {
        /* Transition: '<S3>:277' */
      }

      /* Transition: '<S3>:285' */
      SWatch_DW->is_CronoTime = SWatch_IN_CronoCount;
    } else {
      if (!SWatch_DW->crono_start) {
        /* Transition: '<S3>:272' */
        SWatch_DW->is_CronoTime = SWatch_IN_CronoWait;
      }
    }
  } else {
    /* During 'CronoWait': '<S3>:284' */
    if (SWatch_DW->crono_start) {
      /* Transition: '<S3>:281' */
      SWatch_DW->is_CronoTime = SWatch_IN_CronoCount;
    }
  }

  /* During 'AlarmMng': '<S3>:16' */
  switch (SWatch_DW->is_AlarmMng) {
   case SWatch_IN_AlarmOn:
    /* During 'AlarmOn': '<S3>:153' */
    if ((SWatch_DW->ahours == SWatch_DW->hours) && (SWatch_DW->aminutes ==
         SWatch_DW->minutes) && SWatch_DW->stop) {
      /* Transition: '<S3>:244' */
      if ((SWatch_DW->minutes != SWatch_DW->aminutes) || (!SWatch_DW->stop)) {
        /* Transition: '<S3>:251' */
        SWatch_DW->is_AlarmMng = SWatch_IN_AlarmOn;
      } else if (SWatch_DW->minutes == SWatch_DW->aminutes) {
        /* Transition: '<S3>:249' */
        SWatch_DW->is_AlarmMng = SWatch_IN_Blink;

        /* Entry 'Blink': '<S3>:245' */
        *SWatch_Y_hours = SWatch_DW->ahours;
        *SWatch_Y_minutes = SWatch_DW->aminutes;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    break;

   case SWatch_IN_Blink:
    /* During 'Blink': '<S3>:245' */
    if (SWatch_DW->sfEvent == SWatch_event_Bminus) {
      /* Transition: '<S3>:255' */
      SWatch_DW->alarm = false;
      SWatch_DW->is_AlarmMng = SWatch_IN_wait_alarm;
    } else if (SWatch_DW->sfEvent == SWatch_event_Bplus) {
      /* Transition: '<S3>:305' */
      SWatch_DW->stop = false;
      if ((SWatch_DW->minutes != SWatch_DW->aminutes) || (!SWatch_DW->stop)) {
        /* Transition: '<S3>:251' */
        SWatch_DW->is_AlarmMng = SWatch_IN_AlarmOn;
      } else if (SWatch_DW->minutes == SWatch_DW->aminutes) {
        /* Transition: '<S3>:249' */
        SWatch_DW->is_AlarmMng = SWatch_IN_Blink;

        /* Entry 'Blink': '<S3>:245' */
        *SWatch_Y_hours = SWatch_DW->ahours;
        *SWatch_Y_minutes = SWatch_DW->aminutes;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }
    break;

   case SWatch_IN_delay:
    /* During 'delay': '<S3>:253' */
    if (SWatch_DW->sfEvent == SWatch_event_Bminus) {
      /* Transition: '<S3>:257' */
      SWatch_DW->alarm = false;
      SWatch_DW->is_AlarmMng = SWatch_IN_wait_alarm;
    } else if (SWatch_DW->sfEvent == SWatch_event_Bplus) {
      /* Transition: '<S3>:304' */
      SWatch_DW->stop = false;
      if ((SWatch_DW->minutes != SWatch_DW->aminutes) || (!SWatch_DW->stop)) {
        /* Transition: '<S3>:251' */
        SWatch_DW->is_AlarmMng = SWatch_IN_AlarmOn;
      } else if (SWatch_DW->minutes == SWatch_DW->aminutes) {
        /* Transition: '<S3>:249' */
        SWatch_DW->is_AlarmMng = SWatch_IN_Blink;

        /* Entry 'Blink': '<S3>:245' */
        *SWatch_Y_hours = SWatch_DW->ahours;
        *SWatch_Y_minutes = SWatch_DW->aminutes;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }
    break;

   default:
    /* During 'wait_alarm': '<S3>:152' */
    if (SWatch_DW->alarm) {
      /* Transition: '<S3>:154' */
      SWatch_DW->stop = true;
      SWatch_DW->is_AlarmMng = SWatch_IN_AlarmOn;
    }
    break;
  }

  if (guard3) {
    tmp = (int32_T)(SWatch_DW->seconds + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    if ((uint8_T)((uint32_T)(uint8_T)tmp - ((int32_T)((uint32_T)(uint8_T)tmp >>
           1) << 1)) == 0) {
      /* Transition: '<S3>:254' */
      if ((SWatch_DW->minutes != SWatch_DW->aminutes) || (!SWatch_DW->stop)) {
        /* Transition: '<S3>:251' */
        SWatch_DW->is_AlarmMng = SWatch_IN_AlarmOn;
      } else {
        if (SWatch_DW->minutes == SWatch_DW->aminutes) {
          /* Transition: '<S3>:249' */
          SWatch_DW->is_AlarmMng = SWatch_IN_Blink;

          /* Entry 'Blink': '<S3>:245' */
          *SWatch_Y_hours = SWatch_DW->ahours;
          *SWatch_Y_minutes = SWatch_DW->aminutes;
        }
      }
    }
  }

  if (guard2) {
    tmp = (int32_T)(SWatch_DW->seconds + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    if ((uint8_T)((uint32_T)(uint8_T)tmp - ((int32_T)((uint32_T)(uint8_T)tmp >>
           1) << 1)) == 0) {
      /* Transition: '<S3>:250' */
      SWatch_DW->is_AlarmMng = SWatch_IN_delay;

      /* Entry 'delay': '<S3>:253' */
      *SWatch_Y_hours = 88U;
      *SWatch_Y_minutes = 88U;
      *SWatch_Y_seconds = 88U;
    }
  }

  if (guard1 && (!SWatch_DW->alarm)) {
    /* Transition: '<S3>:156' */
    SWatch_DW->is_AlarmMng = SWatch_IN_wait_alarm;
  }
}

/* Model step function */
void SWatch_step(RT_MODEL_SWatch_T *const SWatch_M, boolean_T SWatch_U_Plus,
                 boolean_T SWatch_U_Minus, boolean_T SWatch_U_TimeMode,
                 boolean_T SWatch_U_TimeSetMode, boolean_T SWatch_U_AlarmMode,
                 boolean_T SWatch_U_SwatchMode, uint8_T *SWatch_Y_hours, uint8_T
                 *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T
                 *SWatch_Y_tenths, uint8_T *SWatch_Y_mode)
{
  DW_SWatch_T *SWatch_DW = ((DW_SWatch_T *) SWatch_M->ModelData.dwork);
  PrevZCX_SWatch_T *SWatch_PrevZCX = ((PrevZCX_SWatch_T *)
    SWatch_M->ModelData.prevZCSigState);
  uint8_T rtb_FixPtSum1;
  boolean_T zcEvent[7];
  boolean_T tmp;
  int32_T i;

  /* Chart: '<S1>/SWatch' incorporates:
   *  TriggerPort: '<S3>/input events'
   */
  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  zcEvent[0] = (((SWatch_DW->Output_DSTATE != 0) !=
                 (SWatch_PrevZCX->SWatch_Trig_ZCE[0] == POS_ZCSIG)) &&
                (SWatch_PrevZCX->SWatch_Trig_ZCE[0] != UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Plus' */
  zcEvent[1] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[1] == POS_ZCSIG) !=
                 SWatch_U_Plus) && (SWatch_PrevZCX->SWatch_Trig_ZCE[1] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Minus' */
  zcEvent[2] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[2] == POS_ZCSIG) !=
                 SWatch_U_Minus) && (SWatch_PrevZCX->SWatch_Trig_ZCE[2] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/TimeMode' */
  zcEvent[3] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[3] == POS_ZCSIG) !=
                 SWatch_U_TimeMode) && (SWatch_PrevZCX->SWatch_Trig_ZCE[3] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/TimeSetMode' */
  zcEvent[4] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[4] == POS_ZCSIG) !=
                 SWatch_U_TimeSetMode) && (SWatch_PrevZCX->SWatch_Trig_ZCE[4] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/AlarmMode' */
  zcEvent[5] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[5] == POS_ZCSIG) !=
                 SWatch_U_AlarmMode) && (SWatch_PrevZCX->SWatch_Trig_ZCE[5] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/SwatchMode' */
  zcEvent[6] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[6] == POS_ZCSIG) !=
                 SWatch_U_SwatchMode) && (SWatch_PrevZCX->SWatch_Trig_ZCE[6] !=
    UNINITIALIZED_ZCSIG));
  tmp = false;
  for (i = 0; i < 7; i++) {
    tmp = (tmp || zcEvent[i]);
  }

  if (tmp) {
    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  UnitDelay: '<S2>/Output'
     */
    /* Gateway: SWatch/SWatch */
    if ((int8_T)(zcEvent[0] ? SWatch_DW->Output_DSTATE != 0 ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S3>:2' */
      SWatch_DW->sfEvent = SWatch_event_tickt;
      SWatch_chartstep_c3_SWatch(SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
    }

    /* Inport: '<Root>/Plus' */
    if ((int8_T)(zcEvent[1] ? SWatch_U_Plus ? RISING_ZCEVENT : FALLING_ZCEVENT :
                 NO_ZCEVENT) == 1) {
      /* Event: '<S3>:7' */
      SWatch_DW->sfEvent = SWatch_event_Bplus;
      SWatch_chartstep_c3_SWatch(SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
    }

    /* Inport: '<Root>/Minus' */
    if ((int8_T)(zcEvent[2] ? SWatch_U_Minus ? RISING_ZCEVENT : FALLING_ZCEVENT :
                 NO_ZCEVENT) == 1) {
      /* Event: '<S3>:8' */
      SWatch_DW->sfEvent = SWatch_event_Bminus;
      SWatch_chartstep_c3_SWatch(SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
    }

    /* Inport: '<Root>/TimeMode' */
    if ((int8_T)(zcEvent[3] ? SWatch_U_TimeMode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S3>:3' */
      SWatch_DW->sfEvent = SWatch_event_Btime;
      SWatch_chartstep_c3_SWatch(SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
    }

    /* Inport: '<Root>/TimeSetMode' */
    if ((int8_T)(zcEvent[4] ? SWatch_U_TimeSetMode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S3>:4' */
      SWatch_DW->sfEvent = SWatch_event_Btimeset;
      SWatch_chartstep_c3_SWatch(SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
    }

    /* Inport: '<Root>/AlarmMode' */
    if ((int8_T)(zcEvent[5] ? SWatch_U_AlarmMode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S3>:5' */
      SWatch_DW->sfEvent = SWatch_event_Balarm;
      SWatch_chartstep_c3_SWatch(SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
    }

    /* Inport: '<Root>/SwatchMode' */
    if ((int8_T)(zcEvent[6] ? SWatch_U_SwatchMode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S3>:6' */
      SWatch_DW->sfEvent = SWatch_event_Bstop;
      SWatch_chartstep_c3_SWatch(SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
    }
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  SWatch_PrevZCX->SWatch_Trig_ZCE[0] = (uint8_T)(SWatch_DW->Output_DSTATE != 0);

  /* Inport: '<Root>/Plus' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[1] = SWatch_U_Plus;

  /* Inport: '<Root>/Minus' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[2] = SWatch_U_Minus;

  /* Inport: '<Root>/TimeMode' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[3] = SWatch_U_TimeMode;

  /* Inport: '<Root>/TimeSetMode' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[4] = SWatch_U_TimeSetMode;

  /* Inport: '<Root>/AlarmMode' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[5] = SWatch_U_AlarmMode;

  /* Inport: '<Root>/SwatchMode' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[6] = SWatch_U_SwatchMode;

  /* Sum: '<S4>/FixPt Sum1' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   *  UnitDelay: '<S2>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)(SWatch_DW->Output_DSTATE + 1U);

  /* Switch: '<S5>/FixPt Switch' */
  if (rtb_FixPtSum1 > 1) {
    /* Update for UnitDelay: '<S2>/Output' incorporates:
     *  Constant: '<S5>/Constant'
     */
    SWatch_DW->Output_DSTATE = 0U;
  } else {
    /* Update for UnitDelay: '<S2>/Output' */
    SWatch_DW->Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S5>/FixPt Switch' */
}

/* Model initialize function */
void SWatch_initialize(RT_MODEL_SWatch_T *const SWatch_M, boolean_T
  *SWatch_U_Plus, boolean_T *SWatch_U_Minus, boolean_T *SWatch_U_TimeMode,
  boolean_T *SWatch_U_TimeSetMode, boolean_T *SWatch_U_AlarmMode, boolean_T
  *SWatch_U_SwatchMode, uint8_T *SWatch_Y_hours, uint8_T *SWatch_Y_minutes,
  uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths, uint8_T *SWatch_Y_mode)
{
  DW_SWatch_T *SWatch_DW = ((DW_SWatch_T *) SWatch_M->ModelData.dwork);
  PrevZCX_SWatch_T *SWatch_PrevZCX = ((PrevZCX_SWatch_T *)
    SWatch_M->ModelData.prevZCSigState);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)SWatch_DW, 0,
                sizeof(DW_SWatch_T));

  /* external inputs */
  (*SWatch_U_Plus) = false;
  (*SWatch_U_Minus) = false;
  (*SWatch_U_TimeMode) = false;
  (*SWatch_U_TimeSetMode) = false;
  (*SWatch_U_AlarmMode) = false;
  (*SWatch_U_SwatchMode) = false;

  /* external outputs */
  (*SWatch_Y_hours) = 0U;
  (*SWatch_Y_minutes) = 0U;
  (*SWatch_Y_seconds) = 0U;
  (*SWatch_Y_tenths) = 0U;
  (*SWatch_Y_mode) = 0U;

  {
    int32_T i;
    for (i = 0; i < 7; i++) {
      SWatch_PrevZCX->SWatch_Trig_ZCE[i] = UNINITIALIZED_ZCSIG;
    }

    /* InitializeConditions for Chart: '<S1>/SWatch' */
    SWatch_DW->is_alarmmode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_swatchmode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->was_swatchmode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_timesetmode = SWatch_IN_NO_ACTIVE_CHILD;

    /* Entry: SWatch/SWatch */
    /* Entry Internal: SWatch/SWatch */
    /* Entry Internal 'Control': '<S3>:14' */
    /* Transition: '<S3>:26' */
    SWatch_DW->ahours = 0U;
    SWatch_DW->aminutes = 0U;
    SWatch_DW->alarm = false;
    SWatch_DW->is_Control = SWatch_IN_timemode;

    /* InitializeConditions for Outport: '<Root>/mode' incorporates:
     *  InitializeConditions for Chart: '<S1>/SWatch'
     */
    /* Entry 'timemode': '<S3>:24' */
    *SWatch_Y_mode = 0U;

    /* InitializeConditions for Chart: '<S1>/SWatch' */
    /* Entry Internal 'TimeCount': '<S3>:15' */
    /* Entry Internal 'Time': '<S3>:287' */
    /* Transition: '<S3>:301' */
    SWatch_DW->hours = 0U;
    SWatch_DW->minutes = 0U;
    SWatch_DW->seconds = 0U;
    SWatch_DW->tenths = 0U;

    /* Entry Internal 'CronoTime': '<S3>:267' */
    /* Transition: '<S3>:279' */
    SWatch_DW->Chours = 0U;
    SWatch_DW->Cminutes = 0U;
    SWatch_DW->Cseconds = 0U;
    SWatch_DW->Ctenths = 0U;
    SWatch_DW->crono_start = false;
    SWatch_DW->is_CronoTime = SWatch_IN_CronoWait;

    /* Entry Internal 'AlarmMng': '<S3>:16' */
    /* Transition: '<S3>:155' */
    SWatch_DW->is_AlarmMng = SWatch_IN_wait_alarm;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
