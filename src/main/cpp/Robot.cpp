// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() {
  Drive(0,0);
}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  Drive(0,0);
  //reseting and starting timer from zero every time autonomous is run
  timer.Reset();
  timer.Start();
}
void Robot::AutonomousPeriodic() {
  std::cout<<"Starting Autonomous Routine"<<std::endl;

  std::cout<<"Autonomous Routine Complete"<<std::endl;
}

void Robot::TeleopInit() {
  Drive(0,0);
}
void Robot::TeleopPeriodic() {
  //calling drive with xbox stick input
  Drive(.5*-m_driverController.GetLeftY(),.5*m_driverController.GetRightY());
  Shoot(m_driverController.GetRightTriggerAxis());
  Intake(m_driverController.GetLeftBumper(),m_driverController.GetRightBumper());
}

void Robot::DisabledInit() {
  Drive(0,0);
}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::Drive(float left, float right){
  //setting motor speeds to parameters
  m_l1.Set(left);
  m_l2.Set(left);
  m_r1.Set(right);
  m_r2.Set(right);
}

void Robot::Shoot(float speed){
  if(m_driverController.GetXButtonPressed()){
    modifier = 0;
    std::cout<<"Gun Speed: "<<modifier*100<<"%"<<std::endl;
  }
  if(m_driverController.GetBButtonPressed()){
    modifier = 0.5;
    std::cout<<"Gun Speed: "<<modifier*100<<"%"<<std::endl;
  }
  if(m_driverController.GetAButtonPressed()){
    modifier = 0.2;
    std::cout<<"Gun Speed: "<<modifier*100<<"%"<<std::endl;
  }
  if(m_driverController.GetYButtonPressed()){
    modifier = 1;
    std::cout<<"Gun Speed: "<<modifier*100<<"%"<<std::endl;
  }
  
  if(speed>0){
    m_gunL.Set(-speed*modifier);
    m_gunR.Set(-speed*modifier);
  }else{
    m_gunL.Set(0);
    m_gunR.Set(0);
  }
}

void Robot::Intake(int out, int in){
  if(in){
    m_conveyor.Set(.5);
    m_intake.Set(-1);
  }else if(out){
    m_conveyor.Set(-.5);
    m_intake.Set(1);
  }else if(in and out){
    m_conveyor.Set(0);
    m_intake.Set(0);
  }else{
    m_conveyor.Set(0);
    m_intake.Set(0);
  }
}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif