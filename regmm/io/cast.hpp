#ifndef _CAST_HPP_
#define _CAST_HPP_

#include "regmm/io/basic_types.hpp"

namespace regmm
{
    template <typename Scalar, int Dim>
    void PointSet_To_TMatrixD(const PointSet& ps, TMatrixD& mat)
    {
        mat.resize(ps.size(), Dim);
        for (size_t i = 0, i_end = ps.size(); i < i_end; ++ i)
        {
            PointType& pt = const_cast<PointSet&>(ps)[i];
            mat(i, 0) = pt.x();
            mat(i, 1) = pt.y();
            if (Dim == 3) mat(i, 2) = pt.z();
        }
    }

    template <typename Scalar, int Dim>
    void MeshObject_To_TMatrixD(const MeshObject& mo, TMatrixD& mat)
    {
        mat.resize(mo.size(), Dim);
        VerticesArray& vts = const_cast<MeshObject&>(mo).getVertices();
        for (size_t i = 0, i_end = vts.size(); i < i_end; ++ i)
        {
            VertexType& vt = vts[i];
            mat(i, 0) = vt.x();
            mat(i, 1) = vt.y();
            if (Dim == 3) mat(i, 2) = vt.z();
        }
    }

    template <typename Scalar, int Dim>
    void TMatrixD_To_PointSet(const TMatrixD& mat, PointSet& ps)
    {
        for (size_t i = 0, i_end = ps.size(); i < i_end; ++ i)
        {
            PointType& pt = ps[i];
            pt.x() = mat(i, 0);
            pt.y() = mat(i, 1);
            if (Dim == 3) pt.z() = mat(i, 2);
        }
    }

    template <typename Scalar, int Dim>
    void TMatrixD_To_MeshObject(const TMatrixD& mat, MeshObject& mo)
    {
        VerticesArray& vts = mo.getVertices();
        for (size_t i = 0, i_end = mo.size(); i < i_end; ++ i)
        {
            VertexType& vt = vts[i];
            vt.x() = mat(i, 0);
            vt.y() = mat(i, 1);
            if (Dim == 3) vt.z() = mat(i, 2);
        }
    }
}
#endif