@test "test cat" {
  run cat in.txt
  [ "$status" -eq 0 ]
  [ "$output" = "$(cat out.txt)" ]
}

@test "test python" {
  run echo hello
  [ "$status" -eq 0 ]
  [ "$output" = "$(python3.5 main.py)" ]
}

@test "test is_isomorphic" {
  run echo 0
  [ "$status" -eq 0 ]
  [ "$output" = "$(python3.5 is_isomorphic.py 1.dig 2.dig)" ]
}

@test "test 2 + 2" {
  run echo 2+2 | bc
  [ "$status" -eq 0 ]
  [ "$output" = "$(4)" ]
}

