@test "test count-nodes for one node digraph" {
  run ./semi --count-nodes one_node.dig
  [ "$status" -eq 0 ]
  [ "$output" = "1" ]
}

@test "test count-nodes for five nodes digraph" {
  run ./semi --count-nodes five_nodes.dig
  [ "$status" -eq 0 ]
  [ "$output" = "5" ]
}
