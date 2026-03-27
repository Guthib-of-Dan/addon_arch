#include <v8.h>
#include <node.h>
using namespace v8;
using args_t = const FunctionCallbackInfo<Value>&;
namespace exports {
  void add(args_t args) {
    Isolate* isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();
    double first = Local<Number>::Cast(args[0])->NumberValue(context).ToChecked();
    double second = Local<Number>::Cast(args[1])->NumberValue(context).ToChecked();
    double result = first + second;
    args.GetReturnValue().Set(
        Number::New(isolate, result)
    );
  }
}
void Initialize(Local<Object> exportsObject) {
  Isolate* isolate = exportsObject->GetIsolate();
  Local<Context> context = isolate->GetCurrentContext();

  auto Register = [exportsObject, isolate, context]<size_t N>(
    const char (&str)[N],
    void(*cb)(args_t)
  ){
    exportsObject->Set(
      context,
      String::NewFromUtf8(isolate, str, NewStringType::kNormal, N-1).ToLocalChecked(),
      FunctionTemplate::New(isolate, cb)->GetFunction(context).ToLocalChecked()
    ).ToChecked();
  };

  Register("add", exports::add);
}

NODE_MODULE(addon, Initialize)
