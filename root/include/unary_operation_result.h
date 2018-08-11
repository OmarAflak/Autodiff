#ifndef UNARY_OPERATION_RESULT
#define UNARY_OPERATION_RESULT

struct UnaryOperationResult {
    double value;
    double grad;

    UnaryOperationResult(const double& value, const double& grad){
        this->value = value;
        this->grad = grad;
    }
};

#endif /* end of include guard: UNARY_OPERATION_RESULT */
