import {createRequire} from "node:module"
var require = createRequire(import.meta.url);
var v8_addon = require("../build/v8.node")
var napi_addon = require("../build/napi.node")

console.log(v8_addon.add(1.5,2.5));
console.log(napi_addon.add(1.5,2.5));
