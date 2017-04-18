#! /bin/sh

DEPLOY_DIR=deploy
OS_NAME=`uname`
ARCH=`uname -m`
BUILD_DATE=`date +%d%m%Y`
BUILD_ID="PREF_"$OS_NAME"_"$ARCH"_"$BUILD_DATE

mkdir $DEPLOY_DIR

cp PREF/PREF $DEPLOY_DIR #Copy executable

cd $DEPLOY_DIR
zip -r ../$BUILD_ID.zip *
cd ..

# Cleanup temporary files
rm -rf PREF/
rm -rf PrefLib/
rm deployed*
rm Makefile
rm -rf $DEPLOY_DIR