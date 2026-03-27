#include <napi.h>
using namespace Napi;
using args_t = const CallbackInfo&;
namespace exports {
  Napi::Number add(args_t args) {
    double first = args[0].As<Number>().DoubleValue();
    double second = args[1].As<Number>().DoubleValue();
    double result = first + second;
    return Number::New(args.Env(), result);
  }
}
Object Initialize(Env env, Object exports) {
  exports.Set("add", Function::New(env, exports::add));
  return exports;
}
NODE_API_MODULE(napi, Initialize)
