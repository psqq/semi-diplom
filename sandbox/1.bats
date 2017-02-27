@test "test cat" {
  run cat in.txt
  [ "$status" -eq 0 ]
  [ "$output" = "$(cat out.txt)" ]
}
