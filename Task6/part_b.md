# Fault Handling Analysis: Motor Jam on Stair-Climbing Robot

## 1. Impact on Robot’s Motion
If one of the crawler motors (left or right) stops due to a motor fault or gear jam:
- The robot will become unbalanced, and the side with the functioning motor will pull the robot in that direction, potentially causing the robot to fall off course.
- The robot may veer off its climbing path, lose stability, and tip over.

## 2. Effects on Balance, Climbing Path, and Risk of Tipping
- **Balance**: The robot's balance will be compromised as one side loses power. The unbalanced forces acting on the robot could cause it to tilt sideways.
- **Climbing Path**: The robot will struggle to climb stairs properly. The track on the non-functional side may either drag or not move at all, causing the robot to slip back or tip over.
- **Risk of Tipping**: The lack of synchronized movement will increase the chance of the robot tipping over, especially if the steps are tall.

## 3. Fault Detection
- **Motor Feedback**: We can use current sensors on each motor to monitor their activity. If the current draw exceeds a threshold (indicating the motor is stuck), it signals a failure.
- **Encoder Feedback**: We can compare the encoder values of both motors. A mismatch in the motor rotation values will indicate a malfunction.
- **IMU Feedback**: The robot's IMU can detect an abnormal tilt or sudden shift in the center of mass, which helps in detecting motor failure.

## 4. Prevention and Recovery Strategies
- **Prevention**: Use a feedback loop where the robot continuously checks the motor’s speed and torque. If either motor slows down or stalls, the robot could stop to prevent further damage or tipping.
- **Recovery**: The robot can engage a **real-time correction algorithm** that adjusts the working motor's speed or attempts to shift weight toward the functioning side. If the fault is detected early, the robot may even back up and reset its position.
