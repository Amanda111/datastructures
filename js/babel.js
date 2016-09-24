var babel = require("babel-core");

var result = babel.transform("code();", options);
result.code;
result.map;
result.ast;


babel.transformFile("es6.js", options, function (err, result) {
  result.code; // => { code, map, ast }
});