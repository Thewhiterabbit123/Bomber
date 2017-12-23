#ifndef IMAGEPOOL_H
#define IMAGEPOOL_H

#include <QPixmap>
#include <memory>
#include <QMap>

template <typename ImageEnum>
class ImagePool
{
public:
    ImagePool(){}

    ImagePool(ImagePool* copying){
        this->m_images = copying->m_images;
    }

    struct LoadException : public std::exception {
      virtual const char* what() const noexcept {
        return "Image not loaded\n";
      }
    };

    void load(ImageEnum id, QString filename, int height, int width) {
        QPixmap frameInit(filename);
        std::shared_ptr<QPixmap> frame(new QPixmap(frameInit.scaled(width, height, Qt::IgnoreAspectRatio, Qt::FastTransformation)));
        m_images[id] = frame;
    }

    std::shared_ptr<QPixmap> get(ImageEnum id) throw(LoadException) {
        if (false == m_images.contains(id))
            throw LoadException();
        return m_images[id];
    }

private:

    QMap<ImageEnum, std::shared_ptr<QPixmap>> m_images;
};

#endif // IMAGEPOOL_H
