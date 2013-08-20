#define BASE_INIT    vsmc::InitializeSEQ
#define BASE_MOVE    vsmc::MoveSEQ
#define BASE_MONITOR vsmc::MonitorEvalSEQ

#include <vsmc/core/sampler.hpp>
#include <vsmc/smp/adapter.hpp>
#include <vsmc/smp/state_matrix.hpp>
#include <vsmc/mrw/normal.hpp>
#include <vsmc/smp/backend_seq.hpp>
