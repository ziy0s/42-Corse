#!/bin/bash

echo -n "Broadcast message from $(whoami)@$(hostname) ("
if [[ "$(tty | awk -F \/ '{print $3}')" == *"tty"* ]]; then
	echo -n "$(tty | awk -F \/ '{print $3}')"
else
	echo -n "somewhere"
fi
echo ") at ($(date)):"
echo " "
echo " "
echo "		#Architecture		: $(uname -a)"
echo "		#CPU physical		: $(nproc)"
echo "		#vCPU			: $(nproc)"
echo "		#Memory Usage		: $(free -h| grep Mem | awk '{print $3}')/$(free -h| grep Mem| awk '{print $2}') ($(free | grep Mem | awk '{print $3/$2 * 100}')%)"
echo "		#Disk Usage		: $(df -h | grep root | awk '{print $3}')/$(df -h| grep root | awk '{print $2}') ($(df -h | grep root| awk '{print $5}'))"
echo "		#CPU load		: $(sar -u 1 1 | tail -n 1 | awk '{print 100 - $8}')%"
echo "		#Last boot		: $(uptime -s)"
echo -n "		#LVM use		: "
if [[ "$(lsblk)" == *"lvm"* ]]; then
	echo "Yes"
else
	echo "No"
fi
echo "		#Connection TCP		: $(ss -tn state established | wc -l) ESTABLISHED"
echo "		#User log		: $(expr $(w | wc -l ) - 2)"
echo "		#Network		: IP $(ip add | grep inet | awk '{print $2}' | grep '[0-255].[0-255].[0-255].[0-255]') ($(cat /sys/class/net/$(ip add | grep dynamic | awk '{print $8}')/address))"
echo "		#Sudo			: $(expr $(cat /var/log/sudo/sudo.log | wc -l) / 2) cmd"
