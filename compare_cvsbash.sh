#!/usr/bin/env bash
echo "tests : output to/dev/null (avoid terminal printspeed overhead)"
echo "timing: BASH 2M (string used '.'):"
echo $(time sh bash_rep.sh "." 2000000 >>/dev/null)
echo "timing: C 2M (string used '.'):"
echo $(time ./rep "." 2000000 >>/dev/null)
