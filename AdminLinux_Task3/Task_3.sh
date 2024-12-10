#!/bin/bash

if [ -f ~/.bashrc ]; then

	echo "file is here"
        echo "HELLO=${HOSTNAME}" >> ~/.bashrc
	echo "LOCAL=$(whoami)"   >> ~/.bashrc

else
	echo "file isn't here"
fi


gnome-terminal 


     echo "new terminal opend"
