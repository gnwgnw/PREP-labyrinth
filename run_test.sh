#!/bin/bash -x
mkdir -p build || exit 1
cd build
cmake .. -DCMAKE_CXX_COMPILER=${COMPILER:-g++} || exit 1
make VERBOSE=1 V=99 || exit 1
rm -f Dungeon_tar.gz
wget http://52.59.17.78:81/lab_data/Dungeon_tar.gz || exit 1
rm -rf Dungeon
tar xvf Dungeon_tar.gz

for level in `seq 1 3`; do
#  ./labyrinth ../lab.txt >log.txt || exit 2
  ./labyrinth Dungeon/lvl_${level}.txt >log.txt || exit 2
  if [ ! -z "$TRAVIS_PULL_REQUEST" ]; then
    STAT=$(cat log.txt | perl -lne '/steps: (\d+), time: (\d+) mcs/ && print "elapsed_mcs=0&steps=0"')
    curl -s https://api.github.com/repos/jirfag/PREP-labyrinth/pulls/${TRAVIS_PULL_REQUEST} >pull.txt || exit 1
    USER=$(cat pull.txt | python -c 'import json; import sys; print(json.loads(sys.stdin.read())["user"]["login"])')
    curl -XPOST http://52.59.17.78:81/maze_results -d "user=${USER}&level_id=${level}&pull_id=${TRAVIS_PULL_REQUEST}&${STAT}"
  fi
done
