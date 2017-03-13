@test "test semi iso for 1-0 and 1-a" {
  run ./semi iso 1-0-semi.txt 1-a-semi.txt
  [ "$status" -eq 0 ]
  [ "$output" = "1" ]
}
