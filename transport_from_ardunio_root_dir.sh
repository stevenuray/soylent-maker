#!/bin/bash

GIT_SOURCE_DIR="/home/osboxes/git/soylent-maker/"
TARGET_ROOT_DIR="/root/Arduino/soylentMakerControllerPulleyWithConveyor/"

ls *.ino  | xargs cp --force --verbose --target-directory ${GIT_SOURCE_DIR}
