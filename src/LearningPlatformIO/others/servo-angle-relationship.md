# Servo Angle Relationship

## Context

We are considering the following names for the legs :

> B --- A -> B-A is the front \
> | ....... | \
> | ....... | \
> | ....... | \
> C --- D -> C-D is the rear

Considering X the name of the leg, all motors will be named with the following convention :

- X_hip
- X_knee
- X_shoulder

## Placement of all the motors on the robot

1. A_shoulder
2. A_hip
3. A_knee
4. B_knee
5. B_hip
6. B_shoulder
7. C_shoulder
8. C_hip
9. C_shoulder
10. D_knee
11. D_hip
12. D_shoulder

> 4 --- 3 -> Front \
> 5 ..... 2 \
> 6 ..... 1 \
> 7 ..... 12 \
> 8 ..... 11 \
> 9 --- 10 -> Rear

## Angle relationship

As a baseline, we will use the angles of the A leg. \
Which means that all others should be expressed in function of A_motor_angle.

1. A_shoulder_angle -> baseline
2. A_hip_angle -> baseline
3. A_knee_angle -> baseline
4. B_knee_angle ->
5. B_hip_angle ->
6. B_shoulder_angle -> ?
7. C_shoulder_angle -> ?
8. C_hip_angle -> map(0, 180, 180, 0)
9. C_knee_angle -> map(0, 180, 180, 0)
10. D_knee_angle -> baseline
11. D_hip_angle -> baseline
12. D_shoulder_angle -> ?

## TODO

Change A leg motor placement

## TO NOTE BETTER

Pour le genou : 90 degrés
Pour la hanche : 180 degrés
