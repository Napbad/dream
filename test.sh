./compile

# shellcheck disable=SC2164
cd ./dap-test/full-test

python test-all.py ../../build/dap_main -d ./ -s ../../src/dap/runtime

echo "Testing finished"