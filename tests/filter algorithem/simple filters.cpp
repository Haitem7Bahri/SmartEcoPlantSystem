#include "filter.h"
 
 /*
  * Limiting filter
  * When a new value has been detected, test the difference between
  * the new value and the former value. If the difference is larger 
  * than the given deviation A, the new value would be abandoned
 */
 
#define DEVIATION  10  //given deviation is set to 10
 
float limit_filter(float new_value)
{
    static int num = 0;
    static float value = 0;  
    num ++;
    if(num == 1)
    	value = new_value;
    else
    {
	    if ( ( new_value - value > DEVIATION ) || ( value - new_value > DEVIATION ))
	        return value;
	}
    return new_value;
}
 
 
#define MIDDLE_FILTER_N  11
 
float middle_filter( float new_value)
{
    static float value_buf[MIDDLE_FILTER_N];
    float temp ;
    int count; int i;
    for ( count = 0; count < MIDDLE_FILTER_N - 1; count++)
    {
        value_buf[count] = value_buf[count + 1] ;
    }
    value_buf[MIDDLE_FILTER_N - 1] = new_value;
 
    for (i = MIDDLE_FILTER_N; i > 0 ; i --)
    {
        if ( value_buf[i] < value_buf[i - 1] )
        {
            temp = value_buf[i];
            value_buf[i] = value_buf[i - 1];
            value_buf[i - 1] = temp;
        }
    }
    return value_buf[(MIDDLE_FILTER_N - 1) / 2];
}
 
#define AVERAGE_N 12
 
float average_filter(float new_value)
{
    static float average_value_buf[AVERAGE_N];
    static  float average_sum = 0;
    int count;
    average_sum -= average_value_buf[0];
    for ( count = 0; count < AVERAGE_N - 1; count++)
    {
        average_value_buf[count] = average_value_buf[count + 1] ;
    }
    average_value_buf[AVERAGE_N - 1] = new_value;
    average_sum += average_value_buf[11];
 
    return (average_sum /(AVERAGE_N * 1.0) );
}
 
 
 
#define FIRST_LAG_PROPORTION 0.4
 
float first_order_lag_filter( float new_value)
{
    static float first_order_value , first_order_last_value;
    first_order_value = first_order_last_value;
    first_order_last_value = new_value;
    return (1 - FIRST_LAG_PROPORTION) * first_order_value + FIRST_LAG_PROPORTION * new_value;
}
 
 
 
#define WEIGHT_AVERAGE_N 12
 
 
 
int  coe[WEIGHT_AVERAGE_N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int  sum_coe = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12;
 
float weighted_filter(float new_value)
{
    static float weight_average_buf[WEIGHT_AVERAGE_N];
    int count;
    float  sum = 0;
    for ( count = 0; count < AVERAGE_N - 1  ; count++)
    {
        weight_average_buf[count] = weight_average_buf[count+ 1] ;
    }
    weight_average_buf[AVERAGE_N - 1] = new_value;
 
    for (count = 0 ; count < WEIGHT_AVERAGE_N; count++)
        sum += weight_average_buf[count] * coe[count];
    return (sum / (sum_coe * 1.0));
}
 
#define SHAKE_N 12
 
float shake_filter( float new_value , float now_value)
{
    static int count = 0;
    if(now_value != new_value)
    {
        count++;
        if (count >= SHAKE_N)
        {
            count = 0;
            return new_value;
        }
    }
    return now_value;
}
 
 
