/**
 * camgen - Camera stream generator (part of simulation environment)
 * Copyright (C) 2008 - 2015 Christian Berger, Bernhard Rumpe
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef CAMGEN_OPENGLGRABBER_H_
#define CAMGEN_OPENGLGRABBER_H_

#include <memory>
#include "opendavinci/odcore/base/KeyValueConfiguration.h"
#include "opendlv/data/camera/ImageGrabberID.h"
#include "opendlv/io/camera/ImageGrabber.h"

namespace core { namespace wrapper { class Image; } }
namespace odcore { namespace wrapper { class SharedMemory; } }
namespace opendlv { namespace data { namespace camera { class ImageGrabberCalibration; } } }
namespace opendlv { namespace data { namespace environment { class EgoState; } } }
namespace opendlv { namespace threeD { class TransformGroup; } }

namespace camgen {

    using namespace std;

    /**
     * This class implements a grabber providing images from
     * a given OpenGL scene.
     */
    class OpenGLGrabber : public opendlv::io::camera::ImageGrabber {
        public:
            enum RENDERING {
                WORLD,
                INTRINSIC_PATTERN,
                EXTRINSIC_PATTERN
            };

        private:
            /**
             * "Forbidden" copy constructor. Goal: The compiler should warn
             * already at compile time for unwanted bugs caused by any misuse
             * of the copy constructor.
             *
             * @param obj Reference to an object of this class.
             */
            OpenGLGrabber(const OpenGLGrabber &);

            /**
             * "Forbidden" assignment operator. Goal: The compiler should warn
             * already at compile time for unwanted bugs caused by any misuse
             * of the assignment operator.
             *
             * @param obj Reference to an object of this class.
             * @return Reference to this instance.
             */
            OpenGLGrabber& operator=(const OpenGLGrabber &);

        public:
            /**
             * Constructor.
             *
             * @param kvc KeyValueConfiguration.
             * @param imageGrabberID Identifier for this image grabber.
             * @param imageGrabberCalibration Calibration information for this grabber.
             * @param egoState Current ego state.
             */
            OpenGLGrabber(const odcore::base::KeyValueConfiguration &kvc,
                          const opendlv::data::camera::ImageGrabberID &imageGrabberID,
                          const opendlv::data::camera::ImageGrabberCalibration &imageGrabberCalibration,
                          opendlv::data::environment::EgoState &egoState);

            virtual ~OpenGLGrabber();

            virtual void delay();

            virtual std::shared_ptr<core::wrapper::Image> getNextImage();

            enum RENDERING m_render;
        private:
            odcore::base::KeyValueConfiguration m_kvc;
            std::shared_ptr<core::wrapper::Image> m_image;
            std::shared_ptr<odcore::wrapper::SharedMemory> m_sharedMemory;
            std::shared_ptr<opendlv::threeD::TransformGroup> m_root;
            std::shared_ptr<opendlv::threeD::TransformGroup> m_extrinsicCalibrationRoot;
            std::shared_ptr<opendlv::threeD::TransformGroup> m_intrinsicCalibrationRoot;
            opendlv::data::environment::EgoState &m_egoState;

            /**
             * This method renders the real word.
             */
            void renderNextImageFromRealWord();

            /**
             * This method renders the root for intrinsic camera calibration.
             */
            void renderNextImageFromIntrinsicCalibrationBody();

            /**
             * This method renders the root for extrinsic camera calibration.
             */
            void renderNextImageFromExtrinsicCalibrationBody();
    };

} // camgen

#endif /*CAMGEN_OPENGLGRABBER_H_*/
