package gocades

/*
#cgo CFLAGS: -I${SRCDIR}/ccades
#cgo LDFLAGS: -L${SRCDIR}/ccades -Wl,-rpath=${SRCDIR}/ccades -lccades
#include "CCadesAbout.h"
*/
import "C"

import (
	"runtime"
)

type GoCadesAbout struct {
	about *C.CCadesAbout
}

func About() *GoCadesAbout {
	ret := &GoCadesAbout{C.CCadesAbout_create()}
	runtime.SetFinalizer(ret, func(obj *GoCadesAbout) {
		C.CCadesAbout_destroy(obj.about)
	})
	return ret
}

func (obj *GoCadesAbout) GetVersion() string {
	val := C.CCadesAbout_get_version(obj.about)
	return C.GoString(val)
}
