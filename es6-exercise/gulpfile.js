var gulp = require("gulp");
var babel = require("gulp-babel");

gulp.task('babel', function() {
  gulp.src('./gulp/*.es6')
    .pipe(babel())
    .pipe(gulp.dest('./gulp/'))
});

gulp.task('default', ['babel']);
