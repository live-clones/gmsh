#include "HLBFGS_wrapper.h"

#if WIN32
// disable int to size_t warning 
#pragma warning(disable: 4267)
#endif

namespace UM {

    namespace Static_Func_Env {
        static const hlbfgs_optimizer::func_grad_eval* local_func_grad = nullptr;
        static const hlbfgs_optimizer::hessian_eval* local_hessian = nullptr;
        static const hlbfgs_optimizer::newiter_callback* local_newiter = nullptr;
        int static_N_for_call_back = 0;

        static void static_func_grad(int N, double* x, double* prev_x, double* f, double* g) {
            (*local_func_grad)(N, x, prev_x, f, g);
        }
        static void static_hessian_eval(int N, double* x, double* prev_x, double* f, double* g, HESSIAN_MATRIX& m_hessian) {
            if (!(local_hessian == nullptr))
                (*local_hessian)(N, x, prev_x, f, g, m_hessian);

        }
        static void static_newiter_callback(int iter, int call_iter, double* x, double* f, double* g, double* gnorm) {
            if (!(local_newiter == nullptr))
                (*local_newiter)(static_N_for_call_back, iter, call_iter, x, f, g, gnorm);
        }
        static hlbfgs_optimizer::func_grad_eval static_fonction_for_simplified;
        static hlbfgs_optimizer::newiter_callback static_callback_for_simplified;

    }

    void hlbfgs_optimizer::optimize(std::vector<double>& sol) {
        assert(func_grad_ != nullptr);
        assert(!sol.empty());

        double parameter[20];
        int hlbfgs_info[20];
        Static_Func_Env::local_func_grad = func_grad_;
        Static_Func_Env::local_hessian = hessian_;
        Static_Func_Env::local_newiter = newiter_;
        Static_Func_Env::static_N_for_call_back = sol.size();

        // initialize parameters and infos
        INIT_HLBFGS(parameter, hlbfgs_info);
        hlbfgs_info[3] = 1; //b_m1qn3_ ? 1 : 0; // determines whether we use m1qn3
        hlbfgs_info[4] = (int)max_iter_;  // max iterations
        hlbfgs_info[5] = (int)verbose_;  // verbose
//      hlbfgs_info[6] = 100;  // the update interval of Hessian
//      hlbfgs_info[10] = 0; // b_cg_ ? 1 : 0; // determines whether we use cg
        parameter[5] = epsg_;
        parameter[6] = epsg_;
        if (hessian_ != nullptr)
            hlbfgs_info[7] = 1;

        HLBFGS( (int)sol.size(),
                (int)5,
                sol.data(),
                Static_Func_Env::static_func_grad,
                Static_Func_Env::static_hessian_eval,
                HLBFGS_UPDATE_Hessian,
                Static_Func_Env::static_newiter_callback,
                parameter,
                hlbfgs_info
              );
    }

    void hlbfgs_optimizer::set_func_grad(const simplified_func_grad_eval* func_grad) {
        assert(func_grad != nullptr);
        Static_Func_Env::static_fonction_for_simplified = [func_grad](int N, double* x, double* , double* f, double* g) {
            std::vector<double> array_x(N), array_g(N);;
            for (int i=0; i<N; i++)
                array_x[i] = x[i];
            (*func_grad)(array_x, *f, array_g);
            for (int i=0; i<N; i++)
                g[i] = array_g[i];

        };
        func_grad_ = &Static_Func_Env::static_fonction_for_simplified;
    }

    void hlbfgs_optimizer::set_newiter(const simplified_newiter_callback* new_iter) {
        assert(new_iter != nullptr);
        Static_Func_Env::static_callback_for_simplified = [new_iter](int N, int iter, int, double* x, double* f, double* g, double* gnorm) {
            std::vector<double> array_x(N), array_g(N);
            for (int i=0; i<N; i++) {
                array_x[i] = x[i];
                array_g[i] = g[i];
            }
            (*new_iter)(iter, array_x, *f, array_g, *gnorm);
        };
        newiter_ = &Static_Func_Env::static_callback_for_simplified;
    }

}

