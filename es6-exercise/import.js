"use strict";

import "babelify/polyfill";
import {bar, Baz} from "./export.js";

bar();
let baz = new Baz();
baz.baz();

new Set();
