#!/usr/bin/env bash

name=""

usage() {
  cat << EOF
Usage: $(basename "$0") -n <NAME>
    or $(basename "$0") <NAME>

Create new directory from problem set template.

Options:
  -h, --help       Display this help message
  -n, --name       Specify a name (required)

Examples:
       $(basename "$0") -n lab_1
   or: $(basename "$0") lab_1
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

cp -r ./.template $name
