#!/usr/bin/env bash

name=""

usage() {
  cat << EOF
Usage: $(basename "$0") -n <NAME>
    or $(basename "$0") <NAME>

Create files for new problem.

Options:
  -h, --help       Display this help message
  -n, --name       Specify a name (required)

Examples:
       $(basename "$0") -n problem_a
   or: $(basename "$0") problem_a
EOF
  exit 1
}

while getopts "hn:" opt; do
  case ${opt} in
    h)
      usage
      ;;
    n)
      name=$OPTARG
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      usage
      ;;
    :)
      echo "Option -$OPTARG requires an argument." >&2
      usage
      ;;
  esac
done

shift $((OPTIND-1))

if [ -z "$name" ] && [ $# -gt 0 ]; then
  name="$1"
  shift
fi

if [ -z "$name" ]; then
  echo "Error: name parameter is required" >&2
  usage
fi

echo $'#include <cstdio>\n#include <iostream>\n\nusing namespace std;\n\n int main() { return 0; }' > "${name}.cpp"
touch "${name}_in.txt"
