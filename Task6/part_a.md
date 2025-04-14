# Robot Design for Stair Climbing

## 1. Mechanism Used
The robot uses a **tracked mechanism** to climb stairs. This mechanism is chosen due to its superior traction and stability on uneven surfaces compared to legged or wheeled designs.

## 2. Justification for Mechanism
The tracked system allows for better weight distribution and stability on stairs, as tracks can cover more surface area, preventing the robot from tipping. This system also provides sufficient friction to grip stairs with varying surfaces.

## 3. Stability and Power Considerations
- **Stability**: The robot's design ensures a low center of mass. This is achieved by placing the motors and battery close to the ground, distributing weight evenly across the tracks.
- **Power**: The robot uses a **12V DC motor** system for the tracks and a separate **5V DC supply** for the control electronics and sensors. Battery life is optimized by utilizing an efficient power management circuit.

## 4. Control Strategy
- **Sensors**: The robot uses an **IMU (Inertial Measurement Unit)** to maintain balance and an **ultrasonic sensor** to detect stairs.
- **Control Logic**: The control system ensures that the robot adapts to step height and maintains balance through feedback loops from the IMU and ultrasonic sensor.

## 5. Stair Detection and Motion Adaptation
- **Detection**: The ultrasonic sensor continuously scans for obstacles and detects the stairs. When the sensor reads a drop (indicating the start of a step), the robot adjusts the track's speed to match the height of the stair.
- **Adaptation**: If the robot detects uneven stairs, it uses a **PID controller** to adjust its movement in real-time, ensuring a smooth climb.

## 6. Block Diagram
![Robot Sketch](images/bot_sketch.png)
