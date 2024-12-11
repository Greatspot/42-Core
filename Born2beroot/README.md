# 🖥️ ABOUT Born2beroot

This system administration project focuses on setting up a secure virtual machine. It covers key topics such as virtualization, partitioning, LVM, command-line tools, SSH, and system security measures like sudo, firewalls, and password policies. The project repository includes a script for automated tasks and the virtual machine signature.

### - 💡 Acknowledgments and Born2beroot project tutorial 🖥

I was able to complete this project by following the [gemartin99's Born2beroot-Tutorial](https://github.com/gemartin99/Born2beroot-Tutorial/blob/main/README_EN.md).

## Debian Version
In my project I used Debian 12.8.0 If you want to use the same version, follow the download link: https://cdimage.debian.org/cdimage/release/12.8.0/amd64/iso-cd/debian-12.8.0-amd64-netinst.iso


## Last Checks
Before submitting the project, we performed some checks to ensure everything was set up correctly. These checks included verifying the Linux release, checking the partitions, verifying sudo installation, checking the hostname, checking password policies, checking UFW and SSH status, checking sudo logs, and verifying user group memberships.

```bash
lsb_release -a || cat /etc/os-release
lsblk
dpkg -l | grep sudo
hostnamectl
sudo chage -l username
sudo ufw status numbered
sudo systemctl status ssh
cd /var/log/sudo/sudo.log && cat sudo.log
getent group sudo
getent group user42
cd /usr/local/bin && bash monitoring.sh
```

After that we will turn off the VM, take a snapshot to keep the instance and generate a signature.txt get with the shasum of vdi.

```bash
sudo shutdown now
sha1sum born2beroot.vdi
cat > signature.txt
```
# ⚙️ How to Test Born2beroot ✅

## Checklist and commands during the evaluation
- [ ] Check if sha1sum of vdi file is equal to signature.txt ```shasum machinename.vdi```
- [ ] Check linux release `lsb_release -a || cat /etc/os-release`
- [ ] Check the partitions `lsblk`
- [ ] Check if sudo in on `dpkg -l | grep sudo`
- [ ] Check the hostname `hostnamectl`
- [ ] Check the password policy `sudo chage -l username`
- [ ] Check UFW `sudo ufw status numbered`
- [ ] Check SSH `sudo systemctl status ssh`
- [ ] Check sudo log `cd /var/log/sudo/` then `cat sudo.log`
- [ ] Check if user is on sudo `getent group sudo`
- [ ] Check if user is on user42 `getent group user42`
- [ ] Run monitoring `cd /usr/local/bin` then `bash monitoring.sh`
- [ ] Create a new user `sudo adduser username`
- [ ] Check the username `cd /etc/passwd | grep username`
- [ ] Create a new group `sudo groupadd evaluating`
- [ ] Add the user to new group `sudo adduser username evaluating`
- [ ] Add the user to sudo `sudo adduser username sudo`
- [ ] Check the changes `getent group evaluating` and `getent group evaluating`
- [ ] Change the hostname `sudo hostnamectl set-hostname newname` && `sudo nano /etc/hosts`
- [ ] reboot, see and see the change `sudo reboot` then `hostnamectl`
- [ ] Restore the original hostname `sudo hostnamectl set-hostname oldname` && `sudo nano /etc/hosts`
- [ ] Add the 8080 port `sudo ufw allow 8080`
- [ ] See the changes `sudo ufw status numbered`
- [ ] Delete the port added `sudo ufw delete 1-9`
- [ ] Check the ip address `sudo ip address`
- [ ] Connect to new user `ssh new_user@hostip.0.0.0 -p 4242`
- [ ] Try to connect to root (Must be fail) `ssh root@hostip.0.0.0 -p 4242` 
- [ ] Change time to 1min `sudo crontab -u root -e `


## - Born2beroot Evaluation commands

[gemartin99's Born2beroot Evaluation commands](https://github.com/gemartin99/Born2beroot-Tutorial/blob/main/README_EN.md#9-2-evaluation-commands-%EF%B8%8F).


## - Born2beroot Correction sheet

[gemartin99's Born2beroot Correction sheet](https://github.com/gemartin99/Born2beroot-Tutorial/blob/main/README_EN.md#9--correction-sheet-).



# Born2beroot Tester ✅

<img width="440" alt="Screen Shot 2023-03-09 at 3 40 54 AM" src="https://user-images.githubusercontent.com/66915274/223902066-f2f6a059-9df8-4e32-a92a-14c43ff8fb0f.png">

## How to use 🛠

In order to clone the repository and use the script we will have to install git on our virtual machine. We update the list of packages on the system.


```sudo apt-get update```

Once we have updated, we install the git package with the following command.

```sudo apt-get install git```

Clone this repository in your Debian virtual machine.

```git clone https://github.com/gemartin99/Born2beroot-Tester.git```

Access to the repository.

```cd Born2beroot-Tester/```

Run the script.

```bash Test.sh```


## Questions

### What is a VM and why is it important?
A VM is a virtual machine that allows multiple machines and operating systems to be installed on a single computer. It is important for conducting different tests on both hardware and software.

### What is the difference between CentOS and Debian?
Debian is more user-friendly, while CentOS is more focused on enterprise usage.

### Why did you choose Debian?
I followed the instructions from the recommended system PDF.

### What are Apt, Aptitude, and Apparmor?
Apt and aptitude are advanced package tools for installing and managing programs. Apt only does exactly what is passed on the command line, while aptitude has better autonomous management. Apparmor protects the system by creating security profiles for each program, restricting access to unused system resources.

### What is LVM?
LVM dynamically manages partitions by creating a group for partitions, allocating space dynamically, and avoiding the need for physical disk formatting when reallocating space.

### What is UFW?
UFW allows for simple configuration of the firewall.

### What is SSH?
SSH is a communication encryption technique between host and client. The communication is protected on both ends.

### What is Cron?
Cron allows for scheduling of programs or scripts to run at a specific time.
