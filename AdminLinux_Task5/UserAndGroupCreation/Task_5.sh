#!/bin/bash

#using groupadd to add new group 
groupadd FamilyName

#using adduser script to add new user
adduser yourname

#add the new user to the exist group
usermod -aG FamilyName yourname

#display contant of the new user 
id yourname

#display contant of the new group
getent group FamilyName


