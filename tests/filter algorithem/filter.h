#ifndef _FILTER_H_
#define _FILTER_H_

#include <stdio.h>
float limit_filter(float new_value);
float middle_filter( float new_value);
float average_filter(float new_value);
float first_order_lag_filter( float new_value);
float weighted_filter(float new_value);
float shake_filter( float new_value , float now_value);

#endif
