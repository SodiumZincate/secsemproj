// This file was generated by qtwaylandscanner
// source file is /build/qt6-wayland/src/qtwayland/src/client/../3rdparty/protocol/xdg-toplevel-drag-v1.xml

#ifndef QT_WAYLAND_XDG_TOPLEVEL_DRAG_V1
#define QT_WAYLAND_XDG_TOPLEVEL_DRAG_V1

#include <QtWaylandClient/private/wayland-xdg-toplevel-drag-v1-client-protocol.h>
#include <QByteArray>
#include <QString>

struct wl_registry;

QT_BEGIN_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_GCC("-Wmissing-field-initializers")
QT_WARNING_DISABLE_CLANG("-Wmissing-field-initializers")
#if !defined(Q_WAYLAND_CLIENT_XDG_TOPLEVEL_DRAG_V1_EXPORT)
#  if defined(QT_SHARED) && !defined(QT_STATIC)
#    if defined(QT_BUILD_WAYLANDCLIENT_LIB)
#      define Q_WAYLAND_CLIENT_XDG_TOPLEVEL_DRAG_V1_EXPORT Q_DECL_EXPORT
#    else
#      define Q_WAYLAND_CLIENT_XDG_TOPLEVEL_DRAG_V1_EXPORT Q_DECL_IMPORT
#    endif
#  else
#    define Q_WAYLAND_CLIENT_XDG_TOPLEVEL_DRAG_V1_EXPORT
#  endif
#endif

namespace QtWayland {
    class Q_WAYLAND_CLIENT_XDG_TOPLEVEL_DRAG_V1_EXPORT xdg_toplevel_drag_manager_v1
    {
    public:
        xdg_toplevel_drag_manager_v1(struct ::wl_registry *registry, uint32_t id, int version);
        xdg_toplevel_drag_manager_v1(struct ::xdg_toplevel_drag_manager_v1 *object);
        xdg_toplevel_drag_manager_v1();

        virtual ~xdg_toplevel_drag_manager_v1();

        void init(struct ::wl_registry *registry, uint32_t id, int version);
        void init(struct ::xdg_toplevel_drag_manager_v1 *object);

        struct ::xdg_toplevel_drag_manager_v1 *object() { return m_xdg_toplevel_drag_manager_v1; }
        const struct ::xdg_toplevel_drag_manager_v1 *object() const { return m_xdg_toplevel_drag_manager_v1; }
        static xdg_toplevel_drag_manager_v1 *fromObject(struct ::xdg_toplevel_drag_manager_v1 *object);

        bool isInitialized() const;

        uint32_t version() const;
        static const struct ::wl_interface *interface();

        enum error {
            error_invalid_source = 0, // data_source already used for toplevel drag
        };

        void destroy();
        struct ::xdg_toplevel_drag_v1 *get_xdg_toplevel_drag(struct ::wl_data_source *data_source);

    private:
        struct ::xdg_toplevel_drag_manager_v1 *m_xdg_toplevel_drag_manager_v1;
    };

    class Q_WAYLAND_CLIENT_XDG_TOPLEVEL_DRAG_V1_EXPORT xdg_toplevel_drag_v1
    {
    public:
        xdg_toplevel_drag_v1(struct ::wl_registry *registry, uint32_t id, int version);
        xdg_toplevel_drag_v1(struct ::xdg_toplevel_drag_v1 *object);
        xdg_toplevel_drag_v1();

        virtual ~xdg_toplevel_drag_v1();

        void init(struct ::wl_registry *registry, uint32_t id, int version);
        void init(struct ::xdg_toplevel_drag_v1 *object);

        struct ::xdg_toplevel_drag_v1 *object() { return m_xdg_toplevel_drag_v1; }
        const struct ::xdg_toplevel_drag_v1 *object() const { return m_xdg_toplevel_drag_v1; }
        static xdg_toplevel_drag_v1 *fromObject(struct ::xdg_toplevel_drag_v1 *object);

        bool isInitialized() const;

        uint32_t version() const;
        static const struct ::wl_interface *interface();

        enum error {
            error_toplevel_attached = 0, // valid toplevel already attached
            error_ongoing_drag = 1, // drag has not ended
        };

        void destroy();
        void attach(struct ::xdg_toplevel *toplevel, int32_t x_offset, int32_t y_offset);

    private:
        struct ::xdg_toplevel_drag_v1 *m_xdg_toplevel_drag_v1;
    };
}

QT_WARNING_POP
QT_END_NAMESPACE

#endif
