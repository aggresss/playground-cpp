#!/usr/bin/env bash
set -e

WORKER_PWD=${PWD}
DEP=$1

expect_dir_name="json_test"
current_dir_name=${WORKER_PWD##*/}
if [ "${current_dir_name}" != "${expect_dir_name}" ] ; then
	echo ">>> [ERROR] $(basename $0) must be called from ${expect_dir_name} directory" >&2
	exit 1
fi

function get_dep()
{
	GIT_REPO="$1"
	GIT_TAG="$2"
	DEST="$3"

	echo ">>> [INFO] getting dep '${DEP}' ..."

	if [ -d "${DEST}" ] ; then
		echo ">>> [INFO] deleting ${DEST} ..."
		git rm -rf --ignore-unmatch ${DEST} > /dev/null
		rm -rf ${DEST}
	fi

	echo ">>> [INFO] cloning ${GIT_REPO} ..."
	git clone ${GIT_REPO} ${DEST}

	cd ${DEST}

	echo ">>> [INFO] setting '${GIT_TAG}' git tag ..."
	git checkout --quiet ${GIT_TAG}
	set -e

	echo ">>> [INFO] adding dep source code to the repository ..."
	rm -rf .git
	git add .

	echo ">>> [INFO] got dep '${DEP}'"

	cd ${WORKER_PWD}
}

function get_jsoncpp()
{
	GIT_REPO="https://github.com/open-source-parsers/jsoncpp.git"
	GIT_TAG="1.8.4"
	DEST="deps/jsoncpp/jsoncpp"

	get_dep "${GIT_REPO}" "${GIT_TAG}" "${DEST}"

	echo ">>> [INFO] running 'python amalgamate.py' ..."
	cd ${DEST}
	# IMPORTANT: avoid default 'dist/' directory since, somehow, it fails.
	python amalgamate.py -s bundled/jsoncpp.cpp
}

function get_json()
{
	GIT_REPO="https://github.com/nlohmann/json.git"
	GIT_TAG="v3.7.3"
	DEST="deps/json"

	get_dep "${GIT_REPO}" "${GIT_TAG}" "${DEST}"

	echo ">>> [INFO] deleting large files and directories ..."
	rm -rf \
        ${DEST}/third_party/
		${DEST}/benchmarks/ \
		${DEST}/doc/ \
		${DEST}/test/ \
		${DEST}/third_party/
}

case "${DEP}" in
	'-h')
		echo "Usage:"
		echo "  ./$(basename $0) [json|jsoncpp]"
		echo
		;;
	json)
		get_json
		;;
	jsoncpp)
		get_jsoncpp
		;;
	*)
		echo ">>> [ERROR] unknown dep '${DEP}'" >&2
		exit 1
esac

if [ $? -eq 0 ] ; then
	echo ">>> [INFO] done"
else
	echo ">>> [ERROR] failed" >&2
	exit 1
fi
