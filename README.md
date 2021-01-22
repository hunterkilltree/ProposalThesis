# ProposalThesis (Unbuntu 18.04 LTS)
Linux command, note, code test, setup environment

# Install RDP server called xrdp (remote use ) too slow
sudo apt-get install xrdp

Check
nmap jetson


Note: log out in physical and login in RDP app

# Install NoMachine (ARM 8) (Using this )
* Download deb file and install.

# Install Chrome
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo apt install ./google-chrome-stable_current_amd64.deb

# View CPU, mem, GPU 
sudo -H pip install jetson-stats
sudo jtop

# Install ROS (melodic ) on Jetson Nano
Execute the following command on terminal one by one:

sudo sh -c 'echo "deb  http://packages.ros.org/ros/ubuntu  $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

Add a new apt key:

sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654

sudo apt update

sudo apt install ros-melodic-desktop

sudo rosdep init

rosdep update

echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc

source ~/.bashrc

rosversion -d

# ROS serial for Arduino 
sudo apt-get install arduino arduino-core
sudo apt-get install ros-melodic-rosserial-arduino
sudo apt-get install ros-melodic-rosserial

sudo usermod -a -G dialout jetbot

rm -rf ros_lib

rosrun rosserial_arduino make_libraries.py /home/jetbot/sketchbook

Open arduino:
arduino
Note : make sure that ros_lib inside sketchbook/lib
# Upload code
 roscore (NO close)
 rosrun rosserial

sudo chmod 777 /dev/ttyACM0
rosrun rosserial_python  serial_node.py  /dev/ttyACM0
check: ls /dev/tty* ; lsusb



# Intall deb file
sudo dpkg -i application.deb

# Allow run .sh file
chmod +x run.sh
# Run sh file
./run.sh

# Remove file and folder
#### Remove file

#### Remove folder


# Hardware testing
#####  RFID

##### TCR5000 line sensor

# Run small warehouse on sim

# Run medium warehouse on sim

# Run custome warehouse on sim

# Run Isaac SDK open Insight web interface

# Isaac sim 2019.3

# Setup Cuda 10.0

# Open Unity  Hub
'''
./UnityHub.AppImage
'''
Note: Unity version 2018.4.30f1
