#include "pybind11/eigen.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "drake/bindings/pydrake/pydrake_pybind.h"
#include "drake/multibody/joints/drake_joint.h"
#include "drake/multibody/joints/fixed_axis_one_dof_joint.h"
#include "drake/multibody/joints/prismatic_joint.h"
#include "drake/multibody/joints/revolute_joint.h"

namespace drake {
namespace pydrake {

PYBIND11_MODULE(joints, m) {
  m.doc() = "Joint types supported by Drake.";

  py::class_<DrakeJoint>(m, "DrakeJoint")
    .def("get_num_positions", &DrakeJoint::get_num_positions)
    .def("get_name", &DrakeJoint::get_name);

  py::class_<PrismaticJoint, DrakeJoint>(m, "PrismaticJoint")
    .def(py::init<const std::string&,
                  const Eigen::Isometry3d&,
                  const Eigen::Vector3d&>(),
         py::arg("name"),
         py::arg("transform_to_parent_body"),
         py::arg("translation_axis"));

  py::class_<RevoluteJoint, DrakeJoint>(m, "RevoluteJoint")
    .def(py::init<const std::string&,
                  const Eigen::Isometry3d&,
                  const Eigen::Vector3d&>(),
         py::arg("name"),
         py::arg("transform_to_parent_body"),
         py::arg("rotation_axis"));
}

}  // namespace pydrake
}  // namespace drake
