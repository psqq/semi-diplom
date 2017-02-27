@test "test count-nodes for one node digraph" {
  run ./semi --count-nodes 1-dig.txt
  [ "$status" -eq 0 ]
  [ "$output" = "1" ]
}

@test "test count-nodes for five nodes digraph" {
  run ./semi --count-nodes line-5-dig.txt
  [ "$status" -eq 0 ]
  [ "$output" = "5" ]
}

@test "test convert digraph to semilattice" {
  run ./semi --to-semi 1-dig.txt 1-semi-out.txt
  [ "$status" -eq 0 ]
  [ "$output" = "$(cat 1-semi.txt)" ]
}
