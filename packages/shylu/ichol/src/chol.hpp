#pragma once
#ifndef __CHOL_HPP__
#define __CHOL_HPP__

/// \file chol.hpp
/// \brief Incomplete Cholesky factorization front interface.
/// \author Kyungjoo Kim (kyukim@sandia.gov)

namespace Example { 

  using namespace std;

  template<int ArgUplo, int ArgAlgo>
  class Chol {
  public:
    static int blocksize;

    // data-parallel interface
    // =======================
    template<typename ParallelForType,
             typename ExecViewType>
    KOKKOS_INLINE_FUNCTION
    static int invoke(typename ExecViewType::policy_type &policy, 
                      const typename ExecViewType::policy_type::member_type &member, 
                      ExecViewType &A);

    // task-data parallel interface
    // ============================
    template<typename ParallelForType,
             typename ExecViewType>
    class TaskFunctor {
    public:
      typedef typename ExecViewType::policy_type policy_type;
      typedef typename policy_type::member_type member_type;
      typedef int value_type;

    private:
      ExecViewType _A;
      
      policy_type &_policy;

    public:
      TaskFunctor(const ExecViewType A)
        : _A(A),
          _policy(ExecViewType::task_factory_type::Policy())
      { } 

      string Label() const { return "Chol"; }
      
      // task execution
      void apply(value_type &r_val) {
        r_val = Chol::invoke<ParallelForType>(_policy, _policy.member_single(), 
                                               _A);
      }

      // task-data execution
      void apply(const member_type &member, value_type &r_val) {
        r_val = Chol::invoke<ParallelForType>(_policy, member, 
                                               _A);
      }

    };

  };

  template<int ArgUplo, int ArgAlgo> int Chol<ArgUplo,ArgAlgo>::blocksize = 32;
}

// basic utils
#include "util.hpp"
#include "partition.hpp"

// unblocked version blas operations
#include "scale.hpp"

// blocked version blas operations
#include "gemm.hpp"
#include "trsm.hpp"
#include "herk.hpp"

// right looking algorithm with upper triangular
#include "chol_unblocked_dummy.hpp"
//#include "chol_unblocked.hpp"
#include "chol_unblocked_opt1.hpp"
#include "chol_unblocked_opt2.hpp"
#include "chol_blocked.hpp"
#include "chol_by_blocks.hpp"

#endif