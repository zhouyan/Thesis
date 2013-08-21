std::vector<std::vector<StateType> > mat(Dim);
for (std::size_t i = 0; i != Dim; ++i)
    mat[i].resize(value.size());
std::vector<std::vector<StateType>::iterator> iter(Dim);
for (std::size_t i = 0; i != Dim; ++i)
    iter[i] = mat[i].begin();
value.read_state_matrix(iter.first());
