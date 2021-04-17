#include <stdio.h>


typedef struct{
    float filterValue;//value after filted
    float kalmanGain;//Kalamn gain
    float A;//State Matrix
    float H;//Measurement Matrix
    float Q;//Variance of SM
    float R;//Variance of MM
    float P;//Predicted Error
    float B;
    float u;
}KalmanInfo;

void Kalm::initKalmanFilter(KalmanInfo *info)
{
    info->A = 1;
    info->H = 1;
    info->P = 0.1;
    info->Q = 0.05;
    info->R = 0.1;
    info->B = 0.1;
    info->u = 0;
    info->filterValue = 0;
}

float Kalm::kalmanFilterFun(KalmanInfo *info, float new_value)
{
    float predictValue = info->A*info->filterValue+info->B*info->u;//Calculate predictvalue
    info->P = info->A*info->A*info->P + info->Q;//Calculate Covariance
    info->kalmanGain = info->P * info->H /(info->P * info->H * info->H + info->R);//Calculate kalman Gain
    info->filterValue = predictValue + (new_value - predictValue)*info->kalmanGain;//Calculate output
    info->P = (1 - info->kalmanGain* info->H)*info->P;//refresh covariance
    return info->filterValue;
}
