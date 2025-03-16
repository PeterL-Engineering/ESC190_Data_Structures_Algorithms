#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    double Kp, Ki, Kd;
    double integral_pitch, integral_height;
    double prev_pitch_err, prev_height_err;
    clock_t prev_time;
} PIDController;

void initialize_PID(PIDController* pid, double Kp, double Ki, double Kd) {
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->integral_pitch = 0;
    pid->integral_height = 0;
    pid->prev_pitch_err = 0;
    pid->prev_height_err = 0;
    pid->prev_time = clock();
}

double system_response(double current_angle, double pid_output) {
    double K = 0.5; // System gain
    return current_angle + K * pid_output;
}

void PID_Controller(PIDController* pid, double pitch_target, double height_target, 
                    double curr_pitch, double curr_height, 
                    double* pitch_output, double* height_output) {
    clock_t curr_time = clock();
    double dt = ((double)(curr_time - pid->prev_time)) / CLOCKS_PER_SEC;
    if (dt < 1e-6) dt = 1e-6;

    double pitch_err = pitch_target - curr_pitch;
    double height_err = height_target - curr_height;

    double pitch_prop = pid->Kp * pitch_err;
    pid->integral_pitch += pid->Ki * pitch_err * dt;
    double pitch_deriv = pid->Kd * (pitch_err - pid->prev_pitch_err) / dt;

    double height_prop = pid->Kp * height_err;
    pid->integral_height += pid->Ki * height_err * dt;
    double height_deriv = pid->Kd * (height_err - pid->prev_height_err) / dt;

    *pitch_output = pitch_prop + pid->integral_pitch + pitch_deriv;
    *height_output = height_prop + pid->integral_height + height_deriv;

    pid->prev_pitch_err = pitch_err;
    pid->prev_height_err = height_err;
    pid->prev_time = curr_time;
}

int main() {
    PIDController pid;
    initialize_PID(&pid, 1, 1, 0);

    double pitch_target = 5.0, height_target = 10.0;
    double curr_pitch = 3.0, curr_height = 8.0;
    double pitch_output, height_output;

    FILE* file = fopen("pid_data.csv", "w");
    if (!file) {
        printf("Error opening file!\n");
        return 1;
    }
    
    fprintf(file, "Time,PitchOutput,CurrentPitch\n");

    for (int t = 0; t < 60; t++) {
        PID_Controller(&pid, pitch_target, height_target, curr_pitch, curr_height, &pitch_output, &height_output);
        curr_pitch = system_response(curr_pitch, pitch_output);
        fprintf(file, "%d,%.5f,%.5f\n", t, pitch_output, curr_pitch);
    }

    fclose(file);
    printf("Data saved to pid_data.csv\n");

    return 0;
}
