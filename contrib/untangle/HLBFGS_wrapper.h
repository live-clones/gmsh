#ifndef __HLBFGS_WRAPPER_H__
#define __HLBFGS_WRAPPER_H__

#include <functional>
#include <vector>
#include <cassert>

#include "HLBFGS.h"

namespace UM {

    struct hlbfgs_optimizer {
        typedef std::function<void(std::vector<double>& x, double &f, std::vector<double>& g)> simplified_func_grad_eval;
        typedef std::function<void(int iter, std::vector<double>& x, double f, std::vector<double>& g, double gnorm)> simplified_newiter_callback;

        typedef std::function<void(int N, double* x, double* prev_x, double* f, double* g)> func_grad_eval;
        typedef std::function<void(int N, double* x, double* prev_x, double* f, double* g, HESSIAN_MATRIX& m_hessian) > hessian_eval;
        typedef std::function<void(int N, int iter, int call_iter, double* x, double* f, double* g, double* gnorm)> newiter_callback;

        static void optimize(const simplified_func_grad_eval& f_g, const simplified_newiter_callback& callback, std::vector<double>& sol) {
            hlbfgs_optimizer object;
            object.set_func_grad(&f_g);
            object.set_newiter(&callback);
            object.optimize(sol);
        }

        static void optimize(const simplified_func_grad_eval f_g, std::vector<double>& sol) {
            hlbfgs_optimizer object;
            object.set_func_grad(&f_g);
            object.optimize(sol);
        }

        hlbfgs_optimizer() {
            func_grad_ = nullptr;
            hessian_ = nullptr;
            newiter_ = nullptr;
        };

        hlbfgs_optimizer(const simplified_func_grad_eval& f_g) : hlbfgs_optimizer() {
            this->set_func_grad(&f_g);
        }

        void set_hessian(const hessian_eval* hessian) {
            assert(hessian != nullptr);
            hessian_ = hessian;
        }

        void set_func_grad(const simplified_func_grad_eval* func_grad);

        void set_func_grad(const func_grad_eval* func_grad) {
            assert(func_grad != nullptr);
            func_grad_ = func_grad;
        }

        void set_newiter(const simplified_newiter_callback* new_iter);

        void set_newiter(const newiter_callback* newiter) {
            assert(newiter != nullptr);
            newiter_ = newiter;
        }

        void set_max_iter(int max_iter) {
            max_iter_ = max_iter;
        }

        void set_verbose(bool verbose) {
            verbose_ = verbose;
        }

        void set_epsg(double epsg) {
            epsg_ = epsg;
        }

        void optimize(std::vector<double>& sol);

        const func_grad_eval* func_grad_;
        const hessian_eval* hessian_;
        const newiter_callback* newiter_;
        int max_iter_ = 10000;
        bool verbose_ = false;
        double epsg_ = 1.0e-10;
    };

}
#endif //__HLBFGS_WRAPPER_H__

