#!/bin/sh
lcm-gen -j *.lcm

export CLASSPATH="`pkg-config --variable=classpath lcm-java`:."

javac lcmtypes/*.java
sleep 1
javac sender.java
