/* Copyright 2021 UFACTORY Inc. All Rights Reserved.
 *
 * Software License Agreement (BSD License)
 *
 * Author: Vinman <vinman.cub@gmail.com>
 ============================================================================*/
 
#include "xarm_planner/xarm_planner.h"
#include <fstream>  // Include the header for file I/O operations
#include <iostream>
#include <string>
#include <sstream>

void exit_sig_handler(int signum)
{
    fprintf(stderr, "[test_xarm_planner_api_pose] Ctrl-C caught, exit process...\n");
    exit(-1);
}

std::string readFirstLineFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    if (std::getline(file, line)) {
        return line;
    }
    return ""; // Return empty string if file is empty or cannot be read
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::NodeOptions node_options;
    node_options.automatically_declare_parameters_from_overrides(true);
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("test_xarm_planner_api_pose", node_options);
    RCLCPP_INFO(node->get_logger(), "test_xarm_planner_api_pose start");

    signal(SIGINT, exit_sig_handler);

    int dof;
    node->get_parameter_or("dof", dof, 7);
    std::string robot_type;
    node->get_parameter_or("robot_type", robot_type, std::string("xarm"));
    std::string group_name = robot_type;
    if (robot_type == "xarm" || robot_type == "lite")
        group_name = robot_type + std::to_string(dof);

    RCLCPP_INFO(node->get_logger(), "namespace: %s, group_name: %s", node->get_namespace(), group_name.c_str());

    xarm_planner::XArmPlanner planner(node, group_name);

    std::ifstream file("output.txt");
    if (file.is_open()) {
        // Define a variable to store the first line as a string
        std::string firstLineStr;
        // Read the first line into the string variable
        std::getline(file, firstLineStr);

        // Convert the string to an integer
        int stored_number;
        std::istringstream iss(firstLineStr);
        iss >> stored_number;

        // Close the file after reading
        file.close();

        // Now you can use the firstLineInt variable as needed
        std::cout << "First line as integer: " << stored_number << std::endl;
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }


/*

    std::string firstLine = readFirstLineFromFile("output.txt");
    int stored_number = std::stoi(firstLine); // Convert string to integer

    int stored_number = 6;
*/
    //variables globales de funciones 
    geometry_msgs::msg::Pose target_pose;
    std::vector<geometry_msgs::msg::Pose> target_poses;
    geometry_msgs::msg::Pose target_pose1;
    geometry_msgs::msg::Pose target_pose2;
    geometry_msgs::msg::Pose target_pose3;
    geometry_msgs::msg::Pose target_pose4;
    geometry_msgs::msg::Pose target_pose5;
    geometry_msgs::msg::Pose target_pose6;
    geometry_msgs::msg::Pose target_pose7;
    geometry_msgs::msg::Pose target_pose8;
    geometry_msgs::msg::Pose target_pose9;
    geometry_msgs::msg::Pose target_pose10;
    geometry_msgs::msg::Pose target_pose11;
    geometry_msgs::msg::Pose target_pose12;

    // cubo
    if (stored_number == 2){

        target_pose1.position.x = 0.3;
        target_pose1.position.y = -0.1;
        target_pose1.position.z = 0.2;
        target_pose1.orientation.x = 1;
        target_pose1.orientation.y = 0;
        target_pose1.orientation.z = 0;
        target_pose1.orientation.w = 0;

        target_pose2.position.x = 0.3;
        target_pose2.position.y = 0.1;
        target_pose2.position.z = 0.2;
        target_pose2.orientation.x = 1;
        target_pose2.orientation.y = 0;
        target_pose2.orientation.z = 0;
        target_pose2.orientation.w = 0;

        target_pose3.position.x = 0.3;
        target_pose3.position.y = 0.1;
        target_pose3.position.z = 0.4;
        target_pose3.orientation.x = 1;
        target_pose3.orientation.y = 0;
        target_pose3.orientation.z = 0;
        target_pose3.orientation.w = 0;

        target_pose4.position.x = 0.3;
        target_pose4.position.y = -0.1;
        target_pose4.position.z = 0.4;
        target_pose4.orientation.x = 1;
        target_pose4.orientation.y = 0;
        target_pose4.orientation.z = 0;
        target_pose4.orientation.w = 0;

        target_pose5.position.x = 0.4;
        target_pose5.position.y = -0.1;
        target_pose5.position.z = 0.4;
        target_pose5.orientation.x = 1;
        target_pose5.orientation.y = 0;
        target_pose5.orientation.z = 0;
        target_pose5.orientation.w = 0;

        target_pose6.position.x = 0.4;
        target_pose6.position.y = 0.1;
        target_pose6.position.z = 0.4;
        target_pose6.orientation.x = 1;
        target_pose6.orientation.y = 0;
        target_pose6.orientation.z = 0;
        target_pose6.orientation.w = 0;

        target_pose7.position.x = 0.4;
        target_pose7.position.y = 0.1;
        target_pose7.position.z = 0.2;
        target_pose7.orientation.x = 1;
        target_pose7.orientation.y = 0;
        target_pose7.orientation.z = 0;
        target_pose7.orientation.w = 0;

        target_pose8.position.x = 0.4;
        target_pose8.position.y = -0.1;
        target_pose8.position.z = 0.2;
        target_pose8.orientation.x = 1;
        target_pose8.orientation.y = 0;
        target_pose8.orientation.z = 0;
        target_pose8.orientation.w = 0;
        while (rclcpp::ok()){
            planner.planPoseTarget(target_pose1);
            planner.executePath();

            planner.planPoseTarget(target_pose2);
            planner.executePath();

            planner.planPoseTarget(target_pose3);
            planner.executePath();
            
            planner.planPoseTarget(target_pose4);
            planner.executePath();
            
            planner.planPoseTarget(target_pose5);
            planner.executePath();

            planner.planPoseTarget(target_pose6);
            planner.executePath();

            planner.planPoseTarget(target_pose3);
            planner.executePath();

            planner.planPoseTarget(target_pose2);
            planner.executePath();
            
            planner.planPoseTarget(target_pose7);
            planner.executePath();

            planner.planPoseTarget(target_pose6);
            planner.executePath();

            planner.planPoseTarget(target_pose7);
            planner.executePath();

            planner.planPoseTarget(target_pose8);
            planner.executePath();

            planner.planPoseTarget(target_pose5);
            planner.executePath();

            planner.planPoseTarget(target_pose8);
            planner.executePath();

            planner.planPoseTarget(target_pose1);
            planner.executePath();

            planner.planPoseTarget(target_pose4);
            planner.executePath();
        }
    }

    // Prisma rect
    if (stored_number == 3){
        target_pose1.position.x = 0.3;
        target_pose1.position.y = -0.1;
        target_pose1.position.z = 0.2;
        target_pose1.orientation.x =1;
        target_pose1.orientation.y = 0;
        target_pose1.orientation.z = 0;
        target_pose1.orientation.w = 0;

        target_pose2.position.x = 0.3;
        target_pose2.position.y = 0.1;
        target_pose2.position.z = 0.2;
        target_pose2.orientation.x = 1;
        target_pose2.orientation.y = 0;
        target_pose2.orientation.z = 0;
        target_pose2.orientation.w = 0;

        target_pose3.position.x = 0.3;
        target_pose3.position.y = 0.1;
        target_pose3.position.z = 0.6;
        target_pose3.orientation.x = 1;
        target_pose3.orientation.y = 0;
        target_pose3.orientation.z = 0;
        target_pose3.orientation.w = 0;

        target_pose4.position.x = 0.3;
        target_pose4.position.y = -0.1;
        target_pose4.position.z = 0.6;
        target_pose4.orientation.x = 1;
        target_pose4.orientation.y = 0;
        target_pose4.orientation.z = 0;
        target_pose4.orientation.w = 0;

        target_pose5.position.x = 0.4;
        target_pose5.position.y = -0.1;
        target_pose5.position.z = 0.6;
        target_pose5.orientation.x = 1;
        target_pose5.orientation.y = 0;
        target_pose5.orientation.z = 0;
        target_pose5.orientation.w = 0;

        target_pose6.position.x = 0.4;
        target_pose6.position.y = 0.1;
        target_pose6.position.z = 0.6;
        target_pose6.orientation.x = 1;
        target_pose6.orientation.y = 0;
        target_pose6.orientation.z = 0;
        target_pose6.orientation.w = 0;

        target_pose7.position.x = 0.4;
        target_pose7.position.y = 0.1;
        target_pose7.position.z = 0.2;
        target_pose7.orientation.x = 1;
        target_pose7.orientation.y = 0;
        target_pose7.orientation.z = 0;
        target_pose7.orientation.w = 0;

        target_pose8.position.x = 0.4;
        target_pose8.position.y = -0.1;
        target_pose8.position.z = 0.2;
        target_pose8.orientation.x = 1;
        target_pose8.orientation.y = 0;
        target_pose8.orientation.z = 0;
        target_pose8.orientation.w = 0;
        while (rclcpp::ok()){
            planner.planPoseTarget(target_pose1);
            planner.executePath();

            planner.planPoseTarget(target_pose2);
            planner.executePath();

            planner.planPoseTarget(target_pose3);
            planner.executePath();
            
            planner.planPoseTarget(target_pose4);
            planner.executePath();
            
            planner.planPoseTarget(target_pose5);
            planner.executePath();

            planner.planPoseTarget(target_pose6);
            planner.executePath();

            planner.planPoseTarget(target_pose3);
            planner.executePath();

            planner.planPoseTarget(target_pose2);
            planner.executePath();
            
            planner.planPoseTarget(target_pose7);
            planner.executePath();

            planner.planPoseTarget(target_pose6);
            planner.executePath();

            planner.planPoseTarget(target_pose7);
            planner.executePath();

            planner.planPoseTarget(target_pose8);
            planner.executePath();

            planner.planPoseTarget(target_pose5);
            planner.executePath();

            planner.planPoseTarget(target_pose8);
            planner.executePath();

            planner.planPoseTarget(target_pose1);
            planner.executePath();

            planner.planPoseTarget(target_pose4);
            planner.executePath();
        }
    }

    // esfera
    if (stored_number == 1){
        float radius = 0.5;
        int numPointsTheta = 5;
        int numPointsPhi = 5;
        float dTheta = M_PI / (numPointsTheta - 1);
        float dPhi = 2 * M_PI / numPointsPhi;
        float posx, posy, posz = 0;

        for (int i = 0; i < numPointsTheta; ++i) {
            float theta = i * dTheta;
            for (int j = 0; j < numPointsPhi; ++j) {
                float phi = j * dPhi;
                posx=(radius * sin(theta) * cos(phi));
                posy=(radius * sin(theta) * sin(phi));
                posz=(radius * cos(theta));
                target_pose.position.x = posx;
                target_pose.position.y = posy;
                target_pose.position.z = posz;
                target_pose.orientation.x = 1;
                target_pose.orientation.y = 0;
                target_pose.orientation.z = 0;
                target_pose.orientation.w = 0;
                std::cout << "Position x: " << target_pose.position.x << ", y: " << target_pose.position.y << ", z: " << target_pose.position.z << std::endl;
                target_poses.push_back(target_pose);
            }
        }
        while (rclcpp::ok()){
            for (auto it = target_poses.begin(); it != target_poses.end(); ++it) {
                const auto& pose = *it;
                // Resto del código
                planner.planPoseTarget(pose);
                planner.executePath();
            }
        }

    }

    //cilinder
    if(stored_number == 4){ 
        float radius = 0.3;
        float height = 0.3;
        int num_points_theta = 10;
        int num_points_z = 3;
        float d_theta = 2 * M_PI / num_points_theta;
        float dz = height / (num_points_z - 1);

        for (int i = 0; i < num_points_theta; ++i) {
            float theta = i * d_theta;
            for (int j = 0; j < num_points_z; ++j) {
                float posz = j * dz;
                float posx = radius * cos(theta);
                float posy = radius * sin(theta);
                target_pose.position.x = posx;
                target_pose.position.y = posy;
                target_pose.position.z = posz;
                target_pose.orientation.x = 1;
                target_pose.orientation.y = 0;
                target_pose.orientation.z = 0;
                target_pose.orientation.w = 0;
                std::cout << "Position x: " << target_pose.position.x << ", y: " << target_pose.position.y << ", z: " << target_pose.position.z << std::endl;
                target_poses.push_back(target_pose);

                target_poses.push_back(target_pose);
            }
        }
        while (rclcpp::ok()){
            for (auto it = target_poses.begin(); it != target_poses.end(); ++it) {
                const auto& pose = *it;
                // Resto del código
                planner.planPoseTarget(pose);
                planner.executePath();
            }
        }

    }

     
        // &&&&&&&&&&&&& SQUARE BASED PYRAMID &&&&&&&&&&&&& //
    if (stored_number == 8){
        target_pose1.position.x = 0.3;
        target_pose1.position.y = 0;
        target_pose1.position.z = 0.2;
        target_pose1.orientation.x = 1;
        target_pose1.orientation.y = 0;
        target_pose1.orientation.z = 0;
        target_pose1.orientation.w = 0;

        target_pose2.position.x = 0.5;
        target_pose2.position.y = 0;
        target_pose2.position.z = 0.2;
        target_pose2.orientation.x = 1;
        target_pose2.orientation.y = 0;
        target_pose2.orientation.z = 0;
        target_pose2.orientation.w = 0;

        target_pose3.position.x = 0.5;
        target_pose3.position.y = 0.2;
        target_pose3.position.z = 0.2;
        target_pose3.orientation.x = 1;
        target_pose3.orientation.y = 0;
        target_pose3.orientation.z = 0;
        target_pose3.orientation.w = 0;

        target_pose4.position.x = 0.3;
        target_pose4.position.y = 0.2;
        target_pose4.position.z = 0.2;
        target_pose4.orientation.x = 1;
        target_pose4.orientation.y = 0;
        target_pose4.orientation.z = 0;
        target_pose4.orientation.w = 0;

        target_pose5.position.x = 0.4;
        target_pose5.position.y = 0.1;
        target_pose5.position.z = 0.6;
        target_pose5.orientation.x = 1;
        target_pose5.orientation.y = 0;
        target_pose5.orientation.z = 0;
        target_pose5.orientation.w = 0;
        while (rclcpp::ok()){
            planner.planPoseTarget(target_pose1);
            planner.executePath();

            planner.planPoseTarget(target_pose2);
            planner.executePath();

            planner.planPoseTarget(target_pose3);
            planner.executePath();

            planner.planPoseTarget(target_pose4);
            planner.executePath();

            planner.planPoseTarget(target_pose1);
            planner.executePath();

            planner.planPoseTarget(target_pose5);
            planner.executePath();

            planner.planPoseTarget(target_pose3);
            planner.executePath();

            planner.planPoseTarget(target_pose4);
            planner.executePath();

            planner.planPoseTarget(target_pose5);
            planner.executePath();

            planner.planPoseTarget(target_pose2);
            planner.executePath();
        }

    }
// &&&&&&&&&&&&& HEXAGONAL PRISM &&&&&&&&&&&&& //
    if(stored_number == 5){
        target_pose1.position.x = 0.3;
        target_pose1.position.y = 0;
        target_pose1.position.z = 0.2;
        target_pose1.orientation.x = 1;
        target_pose1.orientation.y = 0;
        target_pose1.orientation.z = 0;
        target_pose1.orientation.w = 0;

        target_pose2.position.x = 0.4;
        target_pose2.position.y = -0.1;
        target_pose2.position.z = 0.2;
        target_pose2.orientation.x = 1;
        target_pose2.orientation.y = 0;
        target_pose2.orientation.z = 0;
        target_pose2.orientation.w = 0;

        target_pose3.position.x = 0.5;
        target_pose3.position.y = 0;
        target_pose3.position.z = 0.2;
        target_pose3.orientation.x = 1;
        target_pose3.orientation.y = 0;
        target_pose3.orientation.z = 0;
        target_pose3.orientation.w = 0;

        target_pose4.position.x = 0.5;
        target_pose4.position.y = 0.2;
        target_pose4.position.z = 0.2;
        target_pose4.orientation.x = 1;
        target_pose4.orientation.y = 0;
        target_pose4.orientation.z = 0;
        target_pose4.orientation.w = 0;
        
        target_pose5.position.x = 0.4;
        target_pose5.position.y = 0.3;
        target_pose5.position.z = 0.2;
        target_pose5.orientation.x = 1;
        target_pose5.orientation.y = 0;
        target_pose5.orientation.z = 0;
        target_pose5.orientation.w = 0;
        
        target_pose6.position.x = 0.3;
        target_pose6.position.y = 0.2;
        target_pose6.position.z = 0.2;
        target_pose6.orientation.x = 1;
        target_pose6.orientation.y = 0;
        target_pose6.orientation.z = 0;
        target_pose6.orientation.w = 0;
        
        target_pose7.position.x = 0.3;
        target_pose7.position.y = 0;
        target_pose7.position.z = 0.6;
        target_pose7.orientation.x =1;
        target_pose7.orientation.y = 0;
        target_pose7.orientation.z = 0;
        target_pose7.orientation.w = 0;
        
        target_pose8.position.x = 0.4;
        target_pose8.position.y = -0.1;
        target_pose8.position.z = 0.6;
        target_pose8.orientation.x = 1;
        target_pose8.orientation.y = 0;
        target_pose8.orientation.z = 0;
        target_pose8.orientation.w = 0;
        
        target_pose9.position.x = 0.5;
        target_pose9.position.y = 0;
        target_pose9.position.z = 0.6;
        target_pose9.orientation.x = 1;
        target_pose9.orientation.y = 0;
        target_pose9.orientation.z = 0;
        target_pose9.orientation.w = 0;
    
        target_pose10.position.x = 0.5;
        target_pose10.position.y = 0.2;
        target_pose10.position.z = 0.6;
        target_pose10.orientation.x = 1;
        target_pose10.orientation.y = 0;
        target_pose10.orientation.z = 0;
        target_pose10.orientation.w = 0;
    
        target_pose11.position.x = 0.4;
        target_pose11.position.y = 0.3;
        target_pose11.position.z = 0.6;
        target_pose11.orientation.x = 1;
        target_pose11.orientation.y = 0;
        target_pose11.orientation.z = 0;
        target_pose11.orientation.w = 0;
    
        target_pose12.position.x = 0.3;
        target_pose12.position.y = 0.2;
        target_pose12.position.z = 0.6;
        target_pose12.orientation.x = 1;
        target_pose12.orientation.y = 0;
        target_pose12.orientation.z = 0;
        target_pose12.orientation.w = 0;
        while (rclcpp::ok()){
            planner.planPoseTarget(target_pose1);
            planner.executePath();
        
            planner.planPoseTarget(target_pose2);
            planner.executePath();
        
            planner.planPoseTarget(target_pose3);
            planner.executePath();
        
            planner.planPoseTarget(target_pose4);
            planner.executePath();
        
            planner.planPoseTarget(target_pose5);
            planner.executePath();
        
            planner.planPoseTarget(target_pose6);
            planner.executePath();
        
            planner.planPoseTarget(target_pose1);
            planner.executePath();
        
            planner.planPoseTarget(target_pose7);
            planner.executePath();
        
            planner.planPoseTarget(target_pose8);
            planner.executePath();
        
            planner.planPoseTarget(target_pose2);
            planner.executePath();
        
            planner.planPoseTarget(target_pose8);
            planner.executePath();
        
            planner.planPoseTarget(target_pose9);
            planner.executePath();
        
            planner.planPoseTarget(target_pose3);
            planner.executePath();
        
            planner.planPoseTarget(target_pose9);
            planner.executePath();
        
            planner.planPoseTarget(target_pose10);
            planner.executePath();
        
            planner.planPoseTarget(target_pose4);
            planner.executePath();
        
            planner.planPoseTarget(target_pose10);
            planner.executePath();    
        
            planner.planPoseTarget(target_pose11);
            planner.executePath();  
        
            planner.planPoseTarget(target_pose5);
            planner.executePath();  
        
            planner.planPoseTarget(target_pose11);
            planner.executePath();
        
            planner.planPoseTarget(target_pose12);
            planner.executePath();
        
            planner.planPoseTarget(target_pose6);
            planner.executePath();
        
            planner.planPoseTarget(target_pose12);
            planner.executePath();
        
            planner.planPoseTarget(target_pose7);
            planner.executePath();
        }
    }

   // &&&&&&&&&&&&& TRIANGLE BASED PYRAMID &&&&&&&&&&&&& //
   if (stored_number == 6){
        target_pose1.position.x = 0.3;
        target_pose1.position.y = 0;
        target_pose1.position.z = 0.2;
        target_pose1.orientation.x = 1;
        target_pose1.orientation.y = 0;
        target_pose1.orientation.z = 0;
        target_pose1.orientation.w = 0;

        target_pose2.position.x = 0.5;
        target_pose2.position.y = 0.1;
        target_pose2.position.z = 0.2;
        target_pose2.orientation.x = 1;
        target_pose2.orientation.y = 0;
        target_pose2.orientation.z = 0;
        target_pose2.orientation.w = 0;

        target_pose3.position.x = 0.3;
        target_pose3.position.y = 0.2;
        target_pose3.position.z = 0.2;
        target_pose3.orientation.x = 1;
        target_pose3.orientation.y = 0;
        target_pose3.orientation.z = 0;
        target_pose3.orientation.w = 0;

        target_pose4.position.x = 0.4;
        target_pose4.position.y = 0.1;
        target_pose4.position.z = 0.6;
        target_pose4.orientation.x = 1;
        target_pose4.orientation.y = 0;
        target_pose4.orientation.z = 0;
        target_pose4.orientation.w = 0;
        while (rclcpp::ok()){
            planner.planPoseTarget(target_pose1);
            planner.executePath();

            planner.planPoseTarget(target_pose2);
            planner.executePath();

            planner.planPoseTarget(target_pose3);
            planner.executePath();

            planner.planPoseTarget(target_pose1);
            planner.executePath();

            planner.planPoseTarget(target_pose4);
            planner.executePath();

            planner.planPoseTarget(target_pose2);
            planner.executePath();

            planner.planPoseTarget(target_pose3);
            planner.executePath();

            planner.planPoseTarget(target_pose4);
            planner.executePath();
        }
   }

    //cone
    if (stored_number == 7){
        float radius = 0.3;
        float height = 0.4;
        int num_points_theta = 3;
        int num_points_z = 3;
        float d_theta = 2 * M_PI / num_points_theta;
        float dz = height / (num_points_z - 1);

        for (int i = 0; i < num_points_theta; ++i) {
            float theta = i * d_theta;
            for (int j = 0; j < num_points_z; ++j) {
                float posz = j * dz;
                float posx = (radius * (1 - posz / height)) * cos(theta);
                float posy = (radius * (1 - posz / height)) * sin(theta);
                target_pose.position.x = posx;
                target_pose.position.y = posy;
                target_pose.position.z = posz;
                target_pose.orientation.x = 1;
                target_pose.orientation.y = 0;
                target_pose.orientation.z = 0;
                target_pose.orientation.w = 0;
                std::cout << "Position x: " << target_pose.position.x << ", y: " << target_pose.position.y << ", z: " << target_pose.position.z << std::endl;

                target_poses.push_back(target_pose);
            }
        }
        while (rclcpp::ok()){
            for (auto it = target_poses.begin(); it != target_poses.end(); ++it) {
                const auto& pose = *it;
                // Resto del código
                planner.planPoseTarget(pose);
                planner.executePath();
            }
        }
    }

    

    RCLCPP_INFO(node->get_logger(), "test_xarm_planner_api_pose over");
    return 0;
}