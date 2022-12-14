// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

//Included with timed robot skeleton
#include <frc/TimedRobot.h>
//Used to interface with xbox controller
#include <frc/XboxController.h>
//used to control talonSRX and falcon500(talonFX)
//must be added as a vendor library improtant
#include <ctre/Phoenix.h>
//output text library
#include <iostream>
//timer library
#include <frc/Timer.h>


class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;
  //written to control left side and right side independantly with one line
  // Drive(Left side speed (-1 to 1), right side speed (-1 to 1))
  void Drive(float left, float right);
  void Shoot(float speed);
  void Intake(int in, int out);

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  float modifier = 0;
  private:
  //Declaring xbox contoller
  frc::XboxController m_driverController{0};
  //Declaring motors and establishing CAN IDs 
  //use phoenix tuner to get CAN IDs and put them in the brackets
  WPI_TalonFX m_r1{10};
  WPI_TalonFX m_r2{11};

  WPI_TalonFX m_l1{13};
  WPI_TalonFX m_l2{12};

  WPI_TalonSRX m_gunR{3};
  WPI_TalonSRX m_gunL{4};

  WPI_VictorSPX m_conveyor{6};
  WPI_VictorSPX m_intake{8};
  //Declaring timer to use for timed events like autonomous
  frc::Timer timer;
};