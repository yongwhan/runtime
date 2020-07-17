// Copyright 2020 The TensorFlow Runtime Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//===- static_registration.cc ---------------------------------------------===//
//
// This file uses a static constructor to automatically register all of the
// kernels in this directory.  This can be used to simplify clients that don't
// care about selective registration of kernels.
//
//===----------------------------------------------------------------------===//

#include "op_handler_kernels.h"
#include "tfrt/core_runtime/op_handler_factory.h"
#include "tfrt/gpu/core_runtime/gpu_op_handler.h"
#include "tfrt/host_context/kernel_registry.h"

namespace tfrt {

TFRT_STATIC_KERNEL_REGISTRATION(RegisterGpuOpHandlerKernels);

// TODO(b/157120084): Remove after op_handler DSL is deprecated.
static OpHandlerRegistration register_gpu("gpu", GPUOpHandlerFactory);

}  // namespace tfrt